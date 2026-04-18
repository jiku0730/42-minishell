# parse の EBNF

`src/parse/` 配下のパーサが受理する文法を EBNF (ISO/IEC 14977 準拠) で定義する。
トークナイザ (`src/tokenize/`) が生成した `t_list` 上のトークン列を入力とし、`t_ast` の二分木を生成する再帰下降パーサ。

## 文法

```ebnf
list     = pipeline , { ( "&&" | "||" ) , pipeline } ;

pipeline = command , [ "|" , pipeline ] ;

command  = ( redir | WORD ) , { redir | WORD } ;

redir    = redir_op , WORD ;

redir_op = "<" | ">" | ">>" ;

WORD     = ? 演算子トークン ("<", ">", ">>", "|", "&&", "||") および "EOF" センチネル以外のトークン ? ;
```

## エントリポイント

- `parse(t_list *token_head)` — `src/parse/parse_list.c`
  - 内部で `parse_list()` を呼ぶ。
- `parse_pipeline(t_list **current)` — `src/parse/parse.c`
  - `parse_list()` から呼び出される。

## 各プロダクションの実装対応

| プロダクション | 実装 | ソース |
| --- | --- | --- |
| `list` | `parse_list()` | `src/parse/parse_list.c` |
| `pipeline` | `parse_pipeline()` | `src/parse/parse.c` |
| `command` | `parse_cmd()` | `src/parse/parse.c` |
| `redir` | `parse_redir()` | `src/parse/parse.c` |
| トークン判定 | `is_word()`, `is_symbol()`, `is_redir()` | `src/parse/utils/token_check.c` |

## 結合性と AST 構造

- `&&` / `||` (`list`) — **左結合**。`while` ループで左側の `t_ast` に新ノードを重ねていく。
  - 例: `A && B || C` → `OR(AND(A, B), C)`
- `|` (`pipeline`) — **右結合**。右側を再帰呼び出しで構築する。
  - 例: `A | B | C` → `PIPE(A, PIPE(B, C))`
- `command` は葉ノード (`CMD`)。`t_cmd` に `argv` (WORD 列) と `redirs` (リダイレクション列) を保持する。

## AST ノード種別 (`includes/parse.h`)

```c
typedef enum e_ast_type
{
    PIPE,   /* pipeline の内部ノード */
    CMD,    /* command の葉ノード */
    AND,    /* list の "&&" */
    OR      /* list の "||" */
}   t_ast_type;
```

リダイレクション種別:

```c
typedef enum e_redir_kind
{
    R_IN,           /* "<"  */
    R_OUT_TRUNC,    /* ">"  */
    R_OUT_APPEND,   /* ">>" */
    R_NOT_FOUND
}   t_redir_kind;
```

## 備考

- `command` は WORD またはリダイレクションを 1 つ以上含む必要がある。空 CMD は構文エラー (`parse_cmd()` が `NULL` を返す)。これにより `| foo`、`foo |`、`&& foo`、`foo &&` などが検出される。
- `parse_cmd()` のループは WORD でも redir でもないトークン (想定外トークン / 将来追加される未対応演算子) を黙って読み飛ばさず、即座に `NULL` を返す。
- `redir` の WORD 部は `parse_redir()` が `is_word()` で検査し、演算子トークンや末尾 NULL をエラーとして弾く。
- `WORD` トークンは展開 (`$VAR`) とクォート除去を済ませた後の値が渡される前提。
- ヒアドキュメント (`<<`) は本パーサの対象外で、`src/component/heredoc/` が事前段階で処理する。
