# CLAUDE.md

このファイルは Claude Code (claude.ai/code) がこのリポジトリで作業する際のガイダンスを提供する。

## プロジェクト概要

42 Tokyo の minishell プロジェクト。C言語による最小限の POSIX シェル実装。開発者: surayama, kjikuhar。

## ビルドコマンド

```bash
make            # ビルド (libft → ソースを -Wall -Wextra -Werror でコンパイル)
make re         # クリーンビルド
make clean      # オブジェクトファイル削除
make fclean     # オブジェクトファイルとバイナリ削除
make norm       # norminette スタイルチェック
make valgrind   # リビルド後 valgrind でメモリリーク検出 (readline.supp 使用)
make test       # norminette + valgrind 両方実行
make docker     # Docker コンテナをビルドして入る
```

## 実行方法

ビルド・実行は必ずDocker環境内で行うこと。

```bash
make docker          # Docker コンテナをビルドして入る
make                 # コンテナ内でビルド
./minishell          # 通常モード (対話シェル)
./minishell --dev    # 開発モード (expand_checker でパイプラインデバッグ)
```

## Architecture

シェルは以下のインタープリタパイプラインに従う:

```
Input → tokenize() → heredoc() → variable_expand() → remove_quotes() → parser() → AST → execute
```

### パイプラインの各段階

1. **tokenize** (`src/tokenize/`) — 状態機械による字句解析。状態: `IN_NORMAL`, `IN_SINGLE_QUOTE`, `IN_DOUBLE_QUOTE`, `IN_OPERATOR`, `ON_SUCCESS`, `ON_ERROR`。演算子・スペース・クォート境界で `t_list` のトークン文字列に分割する。

2. **変数展開** (`src/component/variable_expand/`) — `$VAR` 構文を展開。クォート文脈を尊重し、シングルクォート内では展開しない。トークナイザと同様の状態機械パターンを使用。

3. **クォート削除** (`src/component/remove_quotes/`) — 展開後のトークンからクォート文字を除去。

4. **parser** (`src/parser/`) — 再帰下降パーサ。二分木ASTを生成。ノード型: `PIPE`(内部ノード)、`CMD`(葉ノード、`t_cmd` に argv リストとリダイレクションリストを持つ)。

5. **実行** — 未実装。エントリポイントは `src/callback/on_input.c`。

### 主要コンポーネント

- **Shell Table** (`src/component/shell_table/`) — 環境変数のハッシュテーブル。export 状態を追跡。関数プレフィックス: `st_*`。
- **ビルトイン** (`src/builtin/`) — echo, pwd, export, unset, cd。全て `(t_list *argv, t_shell_table *shell_table)` を引数に取る。
- **ヒアドキュメント** (`src/component/heredoc/`) — `<<` リダイレクションを処理。一時ファイルを `/tmp/minishell_heredoc_*` に作成。
- **チェッカー** (`src/checker/`) — 各パイプライン段階のデバッグ・テスト用ハーネス。個別に呼び出し可能。

### 主要データ構造 (`includes/`)

- `t_shell_table` / `t_shell_node` — 環境変数ハッシュテーブル (`shell_table.h`)
- `t_ast` — AST木。`t_ast_type` (PIPE/CMD) と left/right 子ノード (`parser.h`)
- `t_cmd` — コマンド。`t_list *argv` と `t_list *redirs` を持つ (`parser.h`)
- `t_redir` — リダイレクション。`t_redir_kind` (R_IN, R_OUT_TRUNC, R_OUT_APPEND) と filename (`parser.h`)
- `t_list` — libft のリンクリスト。トークンリストや引数リストとして全体で使用

## Critical Rules

### コーディング規約 (42 Norminette)

- 1行最大80文字、関数本体最大25行、関数の引数最大4つ
- 変数宣言は関数の先頭、全て snake_case
- typedef: `typedef struct s_name { ... } t_name;`
- 公開ヘッダは `includes/`、非公開ヘッダ (例: `tokenize_private.h`) はソースファイルと同階層
- 全ファイルに 42 ヘッダコメントブロックが必要
- 新規ソースファイルは Makefile の `SRCS_MAND` に追加すること

### メモリリークチェック

- メモリリークの検出は必ず valgrind で行うこと (`make valgrind`)

## 依存関係

- **libft** (`libft/`) — カスタムCライブラリ。Makefile で自動コンパイル
- **readline** — GNU readline。対話入力用 (`-lreadline`)
