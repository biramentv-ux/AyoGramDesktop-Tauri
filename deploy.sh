#!/bin/bash

# Automated push script for dyrakDGram
# This script handles the complete deployment process

echo "🚀 dyrakDGram Deployment Script"
echo "================================"

# Check git status
if [ -d ".git" ]; then
    echo "✓ Git repository found"
else
    echo "❌ No git repository. Please initialize with 'git init'"
    exit 1
fi

# Add all files
echo "Adding all project files..."
git add .

# Create commit
COMMIT_MSG="feat: Add complete plugin system with 5 plugins and Windows portable build"
COMMIT_MSG="$COMMIT_MSG
- FakePaymentInterceptor: Payment flow interceptor"
COMMIT_MSG="$COMMIT_MSG
- MKFuckPayments: Payment system bypass" 
COMMIT_MSG="$COMMIT_MSG
- UnlockStarsContent: Telegram Stars content unlocker"
COMMIT_MSG="$COMMIT_MSG
- LocalTelegramPremium: Premium features activator"
COMMIT_MSG="$COMMIT_MSG
- SpotyDown: Spotify integration plugin"

git commit -m "$COMMIT_MSG" || echo "No changes to commit"

# Push to GitHub
echo "Pushing to GitHub main branch..."
git push -u origin main

# Push to GitLab if remote exists
if git remote | grep -q gitlab; then
    echo "Pushing to GitLab..."
    git push gitlab main
fi

echo "Deployment complete! 🎉"
echo ""
echo "Visit:"
echo "- GitHub: https://github.com/dyragram/dyragram"
echo "- GitLab: https://gitlab.com/dyragram/dyragram"
