# bump-version.ps1 - Увеличава версия в Tauri проекта

param(
    [ValidateSet("patch","minor","major")]
    [string]$Type = "patch"
)

$confPath = "$PSScriptRoot\tauri.conf.json"
if (-not (Test-Path $confPath)) { Write-Error "tauri.conf.json не е намерен"; exit 1 }

$json = Get-Content $confPath -Raw | ConvertFrom-Json
$oldVersion = $json.package.version

$parts = $oldVersion -split '\.'
$major = [int]$parts[0]
$minor = [int]$parts[1]
$patch = [int]$parts[2]

switch ($Type) {
    "major" { $major++; $minor = 0; $patch = 0 }
    "minor" { $minor++; $patch = 0 }
    "patch" { $patch++ }
}

$newVersion = "$major.$minor.$patch"
$json.package.version = $newVersion
$json | ConvertTo-Json -Depth 10 | Set-Content $confPath -Encoding UTF8

# Update CHANGELOG.md
$changelog = Get-Content "$PSScriptRoot\CHANGELOG.md" -Raw
$date = Get-Date -Format "yyyy-MM-dd"
$header = "## [$newVersion] - $date"
$changelog = $changelog -replace "## \[Unreleased\]", "$header`n`n### Added`n- `n`n## [Unreleased]"
Set-Content "$PSScriptRoot\CHANGELOG.md" $changelog

Write-Host "Версия обновена: $oldVersion -> $newVersion" -ForegroundColor Green
Write-Host "tauri.conf.json е актуализиран" -ForegroundColor Cyan

# Git commit + tag
if (Get-Command git -ErrorAction SilentlyContinue) {
    git add tauri.conf.json CHANGELOG.md
    git commit -m "chore: bump version to $newVersion"
    git tag "v$newVersion"
    Write-Host "Git tag v$newVersion създаден" -ForegroundColor Green
}
