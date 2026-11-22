# Makefile.ps1 - Унифициран build интерфейс за dyrakDGram Tauri

param(
    [string]$Target = "help"
)

function Help {
    Write-Host "Цели:" -ForegroundColor Green
    Write-Host "  init     - Инициализирай git repo"
    Write-Host "  build    - Пълен Tauri build + portable"
    Write-Host "  version  - Bump версия patch/minor/major"
    Write-Host "  release  - Build + bump patch + tag"
    Write-Host "  clean    - Изчисти target и dist"
}

switch ($Target.ToLower()) {
    "init" { & "$PSScriptRoot\init-git.ps1" }
    "build" { & "$PSScriptRoot\Build-Tauri.ps1" }
    "version" {
        $type = Read-Host "Тип версия [patch/minor/major]"
        if (-not $type) { $type = "patch" }
        & "$PSScriptRoot\bump-version.ps1" -Type $type
    }
    "release" {
        & "$PSScriptRoot\Build-Tauri.ps1"
        & "$PSScriptRoot\bump-version.ps1" -Type patch
    }
    "clean" {
        Remove-Item -Recurse -Force -ErrorAction SilentlyContinue "$PSScriptRoot\src-tauri\target"
        Remove-Item -Recurse -Force -ErrorAction SilentlyContinue "$PSScriptRoot\dist"
        Remove-Item -Recurse -Force -ErrorAction SilentlyContinue "$PSScriptRoot\release"
        Write-Host "Изчистено" -ForegroundColor Yellow
    }
    default { Help }
}
