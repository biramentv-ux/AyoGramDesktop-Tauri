@echo off
REM dyrakDGram - Push to GitHub and GitLab
echo ========================
echo dyrakDGram Deployment
echo ========================

REM Check if git is initialized
if not exist .git (
    echo Initializing git repository...
    git init
    git add .
    git commit -m "Initial commit: dyrakDGram with all plugins"
) else (
    echo Git repository already initialized.
)

REM Configure git user if not set
git config user.name "dyrakDGram Bot" 2>nul
git config user.email "bot@dyragram.com" 2>nul

REM Set up remotes
echo Setting up remote repositories...

REM GitHub (primary)
git remote add origin https://github.com/dyragram/dyragram.git 2>nul
git remote set-url origin https://github.com/dyragram/dyragram.git 2>nul

REM GitLab (backup mirror)  
git remote add gitlab https://gitlab.com/dyragram/dyragram.git 2>nul

REM Fetch all remotes
echo Fetching remote repositories...
git fetch --all

REM Stage and commit
echo Staging all changes...
git add -A

REM Commit with message
git commit -m "Update dyrakDGram with full plugin integration" -m "- All 5 plugins integrated" -m "- Windows portable version ready" -m "- CI/CD workflow implemented" ^
    || echo No new changes to commit

REM Push to GitHub
echo Pushing to GitHub...
git push -u origin main --force

REM Push to GitLab
git push gitlab main --force

echo Deployment completed successfully!
echo.
echo Repositories:
echo - GitHub: https://github.com/dyragram/dyragram
echo - GitLab: https://gitlab.com/dyragram/dyragram
