#!/bin/bash
# post-edit-norminette.sh

INPUT=$(cat)
FILE_PATH=$(echo "$INPUT" | jq -r '.tool_input.file_path // empty')

# C/H ファイルでない場合はスキップ
if [[ ! "$FILE_PATH" =~ \.(c|h)$ ]]; then
  exit 0
fi

# norminette 実行
NORM_OUTPUT=$(norminette "$FILE_PATH" 2>&1 || true)

if echo "$NORM_OUTPUT" | grep -q "Error"; then
  ERRORS=$(echo "$NORM_OUTPUT" | grep "Error" | head -20)
  cat << EOF
{
  "decision": "block",
  "reason": "norminette エラー:\n$ERRORS"
}
EOF
fi
