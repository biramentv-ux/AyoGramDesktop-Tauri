#!/bin/bash

# dyrakDGram - Push to GitHub and GitLab
# This script pushes all changes to remote repositories

set -e  # Exit on any error

echo "🚀 Starting deployment process..."

# Check if git is initialized
if [ ! -d ".git" ]; then
    echo "❌ Error: No git repository found. Initializing..."
    git init
    git add .
    git commit -m "Initial commit: dyrakDGram with all plugins"
fi

# Configure git user (if not already set)
if ! git config --get user.name > /dev/null 2>&1; then
    echo "⚙️  Configuring git user..."
    git config --global user.name "dyrakDGram Bot"
    git config --global user.email "bot@dyragram.com"
fi

# Add remote repositories
echo "🔗 Setting up remote repositories..."

# GitHub (primary)
if ! git remote | grep -q origin; then
    git remote add origin https://github.com/dyragram/dyragram.git
else
    git remote set-url origin https://github.com/dyragram/dyragram.git
fi

# GitLab (backup mirror)
git remote add gitlab https://gitlab.com/dyragram/dyragram.git 2>/dev/null || true

# Fetch all remotes
git fetch --all

# Stage all changes
echo "📝 Staging all changes..."
git add -A

# Commit changes
git commit -m "Update dyrakDGram with full plugin integration and Windows portable build"     -m "- All 5 plugins integrated: FakePaymentInterceptor, MKFuckPayments, UnlockStarsContent, LocalTelegramPremium, SpotyDown"     "- Windows portable version ready for download"     "- Web frontend with Bulgarian interface"     "- CI/CD workflow implemented"     || echo "No new changes to commit"

# Push to GitHub main branch
echo "🚀 Pushing to GitHub..."
git push -u origin main --force

# Push to GitLab if available
if git remote | grep -q gitlab; then
    echo "🚀 Pushing to GitLab..."
    git push gitlab main --force
fi

echo "✨ Deployment completed successfully!"
echo "📄 Check your repositories:"
echo "   - GitHub: https://github.com/dyragram/dyragram"
echo "   - GitLab: https://gitlab.com/dyragram/dyragram"
