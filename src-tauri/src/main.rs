mod plugins;

use tauri::{Manager, RunEvent};
use dyrak_dgram_lib::init_plugins;

fn main() {
    init_plugins();
    
    tauri::Builder::default()
        .plugin(dy rak_spotydown::init())
        .setup(|app| {
            println!("dyrakDGram application started");
            
            // Initialize all plugins
            let plugins = app.plugins();
            
            // Set up plugin configuration
            app.config().plugins;
            
            Ok(())
        })
        .on_window_event(|window, event| {
            match event {
                RunEvent::WindowClose { label } => {
                    println!("Window {} closed", label);
                }
                _ => {}
            }
        })
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}
