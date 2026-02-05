## やったこと
- シェルの変数展開機能(`$VARIABLE`形式)を実装しました
- `variable_expand`関数と`expand_checker`関数を実装
- 状態機械パターンを使用して、シングル/ダブルクォート内の展開ルールに対応
- トークナイザーの内部構造を改善（`in_normal.c`を複数ファイルに分割）
- リスト操作関数`ft_lstreplace`の不具合を修正

## 懸念点 / レビューしてほしいポイント
- 変数展開のエッジケース（`$`のみ、空変数、未定義変数など）の処理が適切か
- メモリリークがないか（特にエラー時のパス）
- 状態機械の遷移ロジックに漏れがないか
- ダブルクォート内でのエスケープシーケンス処理（今後の実装に備えて）

## 動作確認
- [x] norminetteを通過している
- [x] makeコマンドでビルドできる
- [x] valgrindでリークチェックをした(`valgrind --leak-check=full --suppressions=readline.supp --show-leak-kinds=all -s -q ./minishell`)
- [x] `expand_checker`で基本的な変数展開動作を確認
  - `echo $SHELL` → `[0] "echo" [1] "/bin/zsh"` のように展開される
  - `echo "$USER"` → ダブルクォート内で正しく展開される
  - `echo '$USER'` → シングルクォート内では展開されない（リテラル）
- [x] 空変数・未定義変数の処理確認

## 実装詳細

### 主要な追加ファイル
1. **変数展開コア**:
   - [src/component/variable_expand/variable_expand.c](src/component/variable_expand/variable_expand.c)
   
2. **状態ハンドラ**:
   - [src/component/variable_expand/state/in_normal.c](src/component/variable_expand/state/in_normal.c)
   - [src/component/variable_expand/state/in_double_quote.c](src/component/variable_expand/state/in_double_quote.c)
   - [src/component/variable_expand/state/in_single_quote.c](src/component/variable_expand/state/in_single_quote.c)
   
3. **ストア操作**:
   - [src/component/variable_expand/store/push_token.c](src/component/variable_expand/store/push_token.c)
   - [src/component/variable_expand/store/add_buffer.c](src/component/variable_expand/store/add_buffer.c)
   - [src/component/variable_expand/store/get_key_length.c](src/component/variable_expand/store/get_key_length.c)

4. **テストチェッカー**:
   - [src/checker/expand_checker.c](src/checker/expand_checker.c)

### 技術的特徴
- **状態機械パターン**: クォートの種類に応じた展開ルールを状態遷移で管理
- **内部ヘッダ分離**: 外部インターフェース([variable_expand.h](includes/variable_expand.h))と内部実装([variable_expand_internal.h](includes/variable_expand_internal.h))を分離
- **メモリ安全**: エラーパスでも適切にメモリ解放を実施

### 変更統計
- **新規作成**: 20ファイル
- **変更**: 21ファイル  
- **差分**: +1,067行, -174行

## ひとこと
変数展開の基礎実装が完了しました。次のステップとして、`$?`（終了ステータス）や`$$`（プロセスID）などの特殊変数への対応を予定しています。
<!--
シンプルな感想を書きましょう！
-->
