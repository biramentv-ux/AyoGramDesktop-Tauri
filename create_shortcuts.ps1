# create_shortcuts.ps1 - Създава бързи линкове за RUN и BUILD_AND_RUN

$WshShell = New-Object -ComObject WScript.Shell

function New-Shortcut {
    param($Name, $Target, $Icon)
    $ShortcutPath = Join-Path $PSScriptRoot "$Name.lnk"
    $Shortcut = $WshShell.CreateShortcut($ShortcutPath)
    $Shortcut.TargetPath = $Target
    $Shortcut.WorkingDirectory = $PSScriptRoot
    if (Test-Path $Icon) { $Shortcut.IconLocation = $Icon }
    $Shortcut.Save()
    Write-Host "Създаден: $ShortcutPath" -ForegroundColor Green
}

# Placeholder иконки - създай icons/run.ico и icons/build.ico за по-добър вид
$runIcon = Join-Path $PSScriptRoot "icons\run.ico"
$buildIcon = Join-Path $PSScriptRoot "icons\build.ico"

New-Shortcut "RUN" (Join-Path $PSScriptRoot "RUN.bat") $runIcon
New-Shortcut "BUILD_AND_RUN" (Join-Path $PSScriptRoot "BUILD_AND_RUN.bat") $buildIcon

Write-Host "Готово! Линкове създадени в текущата папка." -ForegroundColor Cyan
