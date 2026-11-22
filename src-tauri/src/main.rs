#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use tauri::{Menu, MenuItem, Submenu, SystemTray, SystemTrayEvent, SystemTrayMenu};
use tauri::Manager;

#[derive(Debug, Clone, serde::Serialize, serde::Deserialize)]
struct GhostModeState {
    invisible_typing: bool,
    hide_read_receipts: bool,
}

#[derive(Debug, Clone, serde::Serialize, serde::Deserialize)]
struct StreamModeState {
    enabled: bool,
    quality: String,
}

#[tauri::command]
fn get_ghost_mode(state: tauri::State<tauri::Mutex<GhostModeState>>) -> Result<GhostModeState, String> {
    let s = state.lock().map_err(|e| e.to_string())?;
    Ok(s.clone())
}

#[tauri::command]
fn toggle_ghost_mode(state: tauri::State<tauri::Mutex<GhostModeState>>, key: String) -> Result<(), String> {
    let mut s = state.lock().map_err(|e| e.to_string())?;
    match key.as_str() {
        "invisible_typing" => s.invisible_typing = !s.invisible_typing,
        "hide_read_receipts" => s.hide_read_receipts = !s.hide_read_receipts,
        _ => return Err(format!("Неизвестен ключ: {}", key)),
    }
    Ok(())
}

#[tauri::command]
fn get_stream_mode(state: tauri::State<tauri::Mutex<StreamModeState>>) -> Result<StreamModeState, String> {
    let s = state.lock().map_err(|e| e.to_string())?;
    Ok(s.clone())
}

#[tauri::command]
fn toggle_stream_mode(state: tauri::State<tauri::Mutex<StreamModeState>>) -> Result<StreamModeState, String> {
    let mut s = state.lock().map_err(|e| e.to_string())?;
    s.enabled = !s.enabled;
    Ok(s.clone())
}

fn main() {
    let ghost_item = MenuItem::with_id("ghost", "Прикрит режим", false, |_| {}).unwrap();
    let stream_item = MenuItem::with_id("stream", "Потоков режим", false, |_| {}).unwrap();
    let hide = MenuItem::with_id("hide", "Скриване", false, |_| {}).unwrap();
    let quit = MenuItem::with_id("quit", "Изход", false, |_| {}).unwrap();

    let tray_menu = SystemTrayMenu::new()
        .add_item(&ghost_item)
        .add_item(&stream_item)
        .add_native_item(tauri::SystemTrayMenuItem::Separator)
        .add_item(&hide)
        .add_item(&quit);

    let system_tray = SystemTray::new().set_menu(tray_menu);

    tauri::Builder::default()
        .system_tray(system_tray)
        .on_system_tray_event(|app, event| match event {
            SystemTrayEvent::MenuItemClicked { id, .. } => match id.as_str() {
                "quit" => app.exit(0),
                "hide" => {
                    if let Some(window) = app.get_window("main") {
                        let _ = window.hide();
                    }
                }
                "ghost" => {
                    if let Some(state) = app.try_state::<tauri::Mutex<GhostModeState>>() {
                        if let Ok(mut s) = state.lock() {
                            s.invisible_typing = !s.invisible_typing;
                        }
                    }
                    println!("Прикрит режим: toggled от системната област");
                }
                "stream" => {
                    if let Some(state) = app.try_state::<tauri::Mutex<StreamModeState>>() {
                        if let Ok(mut s) = state.lock() {
                            s.enabled = !s.enabled;
                        }
                    }
                    println!("Потоков режим: toggled от системната област");
                }
                _ => {}
            },
            _ => {}
        })
        .manage(tauri::Mutex::new(GhostModeState { invisible_typing: false, hide_read_receipts: false }))
        .manage(tauri::Mutex::new(StreamModeState { enabled: false, quality: "720p".into() }))
        .invoke_handler(tauri::generate_handler![
            get_ghost_mode,
            toggle_ghost_mode,
            get_stream_mode,
            toggle_stream_mode
        ])
        .run(|_| {})
        .expect("error while running tauri application");
}
