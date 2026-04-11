# path_resolveの実装計画

## 概要
トークン内のパスを解決するコンポーネント。2つの機能を持つ:
1. **ワイルドカード展開**: `*` を含むトークンをファイルシステムに対してパターンマッチングし、マッチしたファイルパスの一覧に展開する
2. **相対パス解決**: `/` を含むトークン（パスとみなせるもの）を絶対パスに変換する

## 入出力例
```
# ワイルドカード展開
入力トークン: ["ls", "/Users/urassh/*.png"]
出力トークン: ["ls", "/Users/urassh/pic1.png", "/Users/urassh/pic2.png", "/Users/urassh/pic3.png"]

# 相対パス解決
入力トークン: ["ls", "../dir3/tmp.c"]
出力トークン: ["ls", "/Users/urassh/dir3/tmp.c"]
```

## シグネチャ
```c
t_list *resolve_path(t_list *tokens);
void   resolve_path_checker(char *input, t_shell_table *shell_table);
```

## アルゴリズム
1. トークンリストを順に走査する
2. 各トークンに対して以下の判定を行う:

### A. ワイルドカードを含む場合（`*` あり）
   a. `ft_strrchr(token, '/')` で最後の `/` を見つけ、ディレクトリ部とパターン部に分割
      - `/Users/urassh/*.png` → dir: `/Users/urassh/`, pattern: `*.png`
      - `*.c`（`/`なし）→ dir: `.`, pattern: `*.c`
   b. `to_absolute_path(dir)` でディレクトリを絶対パスに変換
   c. `get_directory_entries(abs_dir, hidden, &entries)` でディレクトリ内のエントリ一覧を取得
      - パターンが `.` 始まりなら隠しファイルも含める
   d. `filter_pattern(entries, pattern)` でパターンにマッチするエントリを絞り込む
   e. マッチした各エントリに `abs_dir + "/" + entry` のフルパスを構築する
   f. `ft_lstreplace(prev, current, resolved)` で元のトークンをマッチ結果リストに置換する
   g. マッチ結果が0件の場合、元のトークンをそのまま残す

### B. パスを含む場合（`/` あり、`*` なし）
   a. `to_absolute_path(token)` で絶対パスに変換
   b. トークンの内容を変換後の絶対パスに置き換える（contentをfree→新しいcontentに差し替え）

### C. それ以外
   - そのまま次へ進む

## 利用する既存コンポーネント
| 関数 | ファイル | 役割 |
|------|---------|------|
| `to_absolute_path()` | `src/component/path/to_absolute_path.c` | 相対パス→絶対パス変換 |
| `filter_pattern()` | `src/component/pattern/filter_pattern.c` | ワイルドカードパターンマッチング |
| `get_directory_entries()` | `src/component/directory/get_directory_entries.c` | ディレクトリ内エントリ取得 |
| `ft_lstreplace()` | `libft/list/ft_lstreplace.c` | リスト要素の置換 |
| `ft_strrchr()` | `libft/` | 最後の文字検索（dir/pattern分割） |

## ファイル構成
```
includes/path_resolve.h                        # ヘッダ（resolveの宣言）
src/component/path_resolve/path_resolve.c      # メインロジック（resolve, has_wildcard, resolve_token, build_full_paths）
src/checker/resolve_checker.c                  # 開発用チェッカー
```

## 関数設計（path_resolve.c）

### `t_list *resolve_path(t_list *tokens)`
- トークンリストを走査し、ワイルドカード展開・相対パス解決を行う
- prev/currentでリストを辿り、ワイルドカード時は`ft_lstreplace`で置換
- パス時はcontent差し替え
- 先頭トークンが置換された場合は新しいheadを返す

### `static bool has_wildcard(const char *str)`
- 文字列に `WILDCARD('*')` が含まれるか判定

### `static bool has_path(const char *str)`
- 文字列に `/` が含まれるか判定（パスとみなせるか）

### `static t_list *resolve_wildcard(const char *token)`
- 単一トークンのワイルドカード解決
- dir部とpattern部に分割 → to_absolute_path → get_directory_entries → filter_pattern → フルパス構築

### `static t_list *build_full_paths(t_list *matches, const char *abs_dir)`
- マッチしたファイル名リストに `abs_dir + "/"` を付与してフルパスリストを構築

## Makefileへの変更
`SRCS_MAND` に以下を追加:
```
src/component/path_resolve/path_resolve.c
src/checker/resolve_checker.c
```

## minishell.hへの変更
- `#include "path_resolve.h"` を追加
- `void resolve_checker(char *input, t_shell_table *shell_table);` を宣言に追加

## 実装後の検証
実装完了後、必ず以下を実行してnorminetteに準拠していることを確認する:
```bash
docker compose exec minishell norminette src/component/path_resolve/ src/checker/resolve_checker.c includes/path_resolve.h
```
