# init-git.ps1 - Инициализирай git repo за AyoGramDesktop Tauri

Write-Host "Инициализация на Git repo..." -ForegroundColor Green

if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
    Write-Host "Git не е намерен, инсталирам..." -ForegroundColor Yellow
    winget install -e --id Git.Git --accept-package-agreements --accept-source-agreements
}

git init

# Създай .gitignore ако го няма
if (-not (Test-Path .gitignore)) {
    @"
# Tauri / Rust
/target
/src-tauri/target
/.tauri

# Node / Vite
node_modules
/dist
/.vite

# pnpm
.pnpm-store

# IDE
.vscode
.idea

# OS
.DS_Store
Thumbs.db

# Builds
/release
/build
/*.exe
/*.msi

# Misc
*.log
.env
"@ | Set-Content .gitignore
}

git add .

$msg = Read-Host "Commit message [Initial Tauri hybrid]"
if ([string]::IsNullOrWhiteSpace($msg)) { $msg = "Initial Tauri hybrid" }

git commit -m $msg

Write-Host "Git repo инициализиран." -ForegroundColor Green
Write-Host "Файлове добавени:" -ForegroundColor Cyan
git ls-files --cached | Select-Object -First 20
