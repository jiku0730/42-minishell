#!/bin/bash
# pre-bash-safety-check.sh

INPUT=$(cat)
COMMAND=$(echo "$INPUT" | jq -r '.tool_input.command // empty')

DANGEROUS_PATTERNS=(
  "rm -rf /"
  "git push --force.*main"
  "git push --force.*develop"
)

for pattern in "${DANGEROUS_PATTERNS[@]}"; do
  if echo "$COMMAND" | grep -qE "$pattern"; then
    cat << EOF
{
  "decision": "Reject",
  "feedback": "🚨 危険なコマンドがブロックされました

コマンド: \`$COMMAND\`"
}
EOF
    exit 0
  fi
done
