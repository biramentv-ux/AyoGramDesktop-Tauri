#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")] 

use tauri::{Menu, MenuItem, Submenu, SystemTray, SystemTrayEvent, SystemTrayMenu};
use tauri::Manager;

#[derive(Debug, serde::Serialize)]
struct GhostModeState {
    invisible_typing: bool,
    hide_read_receipts: bool,
}

#[derive(Debug, serde::Serialize)]
struct StreamModeState {
    enabled: bool,
    quality: String,
}

#[tauri::command]
fn get_ghost_mode(state: tauri::State<GhostModeState>) -> GhostModeState {
    state.inner().clone()
}

#[tauri::command]
fn toggle_ghost_mode(state: tauri::State<tauri::Mutex<GhostModeState>>, key: String) -> Result<(), String> {
    let mut s = state.lock().unwrap();
    match key.as_str() {
        "invisible_typing" => s.invisible_typing = !s.invisible_typing,
        "hide_read_receipts" => s.hide_read_receipts = !s.hide_read_receipts,
        _ => return Err("Unknown key".into()),
    }
    Ok(())
}

#[tauri::command]
fn get_stream_mode(state: tauri::State<StreamModeState>) -> StreamModeState {
    state.inner().clone()
}

fn main() {
    let quit = MenuItem::with_id("quit", "Exit", false, |_| {})
        .unwrap();
    let hide = MenuItem::with_id("hide", "Hide", false, |_| {}).unwrap();
    let tray_menu = SystemTrayMenu::new()
        .add_item(&MenuItem::with_id("ghost", "Ghost Mode", false, |_| {}).unwrap())
        .add_item(&MenuItem::with_id("stream", "Stream Mode", false, |_| {}).unwrap())
        .add_native_item(tauri::SystemTrayMenuItem::Separator)
        .add_item(&hide)
        .add_item(&quit);

    let system_tray = SystemTray::new().set_menu(tray_menu);

    let ghost_state = tauri::State::new(tauri::Mutex::new(GhostModeState {
        invisible_typing: false,
        hide_read_receipts: false,
    }));
    let stream_state = tauri::State::new(StreamModeState {
        enabled: false,
        quality: "720p".into(),
    });

    tauri::Builder::default()
        .system_tray(system_tray)
        .on_system_tray_event(|app, event| match event {
            SystemTrayEvent::MenuItemClicked { id, .. } => match id.as_str() {
                "quit" => {
                    app.exit(0);
                }
                "hide" => {
                    let window = app.get_window("main").unwrap();
                    window.hide().unwrap();
                }
                "ghost" => {
                    println!("Ghost Mode toggled from tray");
                }
                "stream" => {
                    println!("Stream Mode toggled from tray");
                }
                _ => {}
            },
            _ => {}
        })
        .manage(tauri::Mutex::new(GhostModeState { invisible_typing: false, hide_read_receipts: false }))
        .manage(StreamModeState { enabled: false, quality: "720p".into() })
        .invoke_handler(tauri::generate_handler![get_ghost_mode, toggle_ghost_mode, get_stream_mode])
        .run(|_| {})
        .expect("error while running tauri application");
}
