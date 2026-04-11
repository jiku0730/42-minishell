# Execute の設計

`jiku/feature/execute` ブランチに実装済み。

## ファイル構成

```
src/execute/
├── exec_ast.c               # エントリーポイント。ASTノードを PIPE/CMD に振り分け
├── exec_cmd.c               # CMDノードの実行。リダイレクション処理 → 外部コマンド実行
├── exec_pipe.c              # PIPEノードの実行。左右を fork して pipe でつなぐ
├── pipe/
│   └── exec_pipe_child.c   # 子プロセス内の fd 付け替え（dup2）と再帰実行
├── command/
│   ├── exec_external_cmd.c # execve() による外部コマンド実行
│   └── list_to_argv.c      # t_list のトークンリストを char** argv に変換
├── redirects/
│   └── exec_redirs.c       # リダイレクションの適用（<, >, >>）
└── utils/
    ├── ft_wifexited.c       # WIFEXITED マクロの代替実装
    └── ft_wexitstatus.c     # WEXITSTATUS マクロの代替実装
```

## 実行フロー

### シングルコマンド（`ls -la`）

```
exec_ast(CMD)
  └─ exec_cmd()
       ├─ exec_redirs()           # リダイレクションを dup2 で適用
       ├─ list_to_argv()          # t_list → char** に変換
       └─ exec_external_cmd()
            ├─ find_exec_path()   # $PATH を走査してフルパスを取得
            ├─ export_envp()      # shell_table → envp[] に変換
            └─ execve()           # プロセスを置き換えて実行
```

### パイプ（`ls | grep src`）

```
exec_ast(PIPE)
  └─ exec_pipe()
       ├─ pipe(fd)                        # パイプを作成
       ├─ fork() → exec_left_child()
       │    ├─ dup2(fd[1], STDOUT)        # 左側の stdout → パイプ書き込み端
       │    └─ exec_ast(node->left)       # 左ノードを再帰実行
       ├─ fork() → exec_right_child()
       │    ├─ dup2(fd[0], STDIN)         # 右側の stdin → パイプ読み込み端
       │    └─ exec_ast(node->right)      # 右ノードを再帰実行
       ├─ close(fd[0]), close(fd[1])
       ├─ waitpid(left)
       └─ waitpid(right) → 右側の終了ステータスを返す
```

パイプは左右それぞれを別プロセスで並行実行し、親は両方の終了を待つ。
終了ステータスは右側（最後のコマンド）のものを使う。

### リダイレクション（`exec_redirs.c`）

リダイレクションは `exec_cmd()` がコマンドを実行する前に適用する。
複数のリダイレクションがある場合はリストの順に処理する。

| 記法      | 処理 |
|-----------|------|
| `< file`  | `open(O_RDONLY)` → `dup2(fd, STDIN_FILENO)` |
| `> file`  | `open(O_WRONLY\|O_CREAT\|O_TRUNC, 0644)` → `dup2(fd, STDOUT_FILENO)` |
| `>> file` | `open(O_WRONLY\|O_CREAT\|O_APPEND, 0644)` → `dup2(fd, STDOUT_FILENO)` |
| `<< EOF`  | `heredoc()` が事前に tmpfile に変換済みのため `< tmpfile` として処理 |

## 注意点・既知の問題

### ビルトイン未対応

`exec_cmd()` は現在すべてのコマンドを `exec_external_cmd()` に渡している。
`echo`, `pwd`, `cd`, `export`, `unset`, `exit` を判別してビルトイン関数に
振り分けるディスパッチ処理が必要。

### exit コードのバグ

`exec_external_cmd()` で `find_exec_path()` が `NULL` を返したとき（= コマンドが
見つからない）に `126` を返しているが、正しくは `127`。`126` は「ファイルは
存在するが実行権限がない」場合に使う。

### パイプ内のビルトイン

パイプの子プロセス内でビルトインが呼ばれた場合、その副作用（`cd` による
`PWD` 変更など）は親プロセスには反映されない。これは bash の仕様通りの挙動。
