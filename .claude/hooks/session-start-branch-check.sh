#!/bin/bash
# session-start-branch-check.sh

CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)

if [ "$CURRENT_BRANCH" = "develop" ] || [ "$CURRENT_BRANCH" = "main" ]; then
  cat << EOF
{
  "decision": "Proceed",
  "feedback": "⚠️ 現在のブランチ: **$CURRENT_BRANCH**

開発作業は feature ブランチでおこなってください。"
}
EOF
fi
