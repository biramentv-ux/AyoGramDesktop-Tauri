# publish.ps1 - Пълен release pipeline

param(
    [ValidateSet("patch","minor","major")]
    [string]$Type = "patch"
)

Write-Host "=== Publish Release ===" -ForegroundColor Green

# 1. Bump версия
& "$PSScriptRoot\bump-version.ps1" -Type $Type

# 2. Вземи нова версия
$version = (Get-Content "$PSScriptRoot\tauri.conf.json" | ConvertFrom-Json).package.version
$tag = "v$version"

# 3. Подготви release notes
$changelog = Get-Content "$PSScriptRoot\CHANGELOG.md" -Raw
$notes = Get-Content "$PSScriptRoot\release-notes.md" -Raw
$notes = $notes -replace "\{\{VERSION\}\}", $version
$notes = $notes -replace "\{\{CHANGELOG\}\}", ($changelog -split "\r?\n## \[" | Select-Object -First 2 | Join-String)
$notes | Set-Content "$PSScriptRoot\release-notes-generated.md"

Write-Host "Release notes генерирани" -ForegroundColor Cyan

# 4. Git push
if (Get-Command git -ErrorAction SilentlyContinue) {
    git push origin main
    git push origin $tag
    Write-Host "Git push извършен: main + $tag" -ForegroundColor Green
}

# 5. Инфо
Write-Host "Готово! GitHub Actions ще стартира автоматично за $tag" -ForegroundColor Green
Write-Host "Следи прогреса в: https://github.com/<user>/<repo>/actions" -ForegroundColor Yellow
