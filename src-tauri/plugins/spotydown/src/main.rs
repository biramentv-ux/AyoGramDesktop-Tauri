// Main module for SpotyDown plugin

mod webview;
mod utils;

use tauri::{custom_protocol, Manager};

fn main() {
    tauri::Builder::default()
        .setup(|app| {
            println!("SpotyDown plugin initialized");
            Ok(())
        })
        .run(tauri::generate_context!())
        .expect("error while running SpotyDown application");
}
