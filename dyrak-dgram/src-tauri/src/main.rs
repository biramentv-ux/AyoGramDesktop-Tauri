fn main() {
    tauri::Builder::default()
        .setup(|app| {
            println!("dyrakDGram initialized successfully");
            Ok(())
        })
        .run(tauri::generate_context!())
        .expect("Error while running dyrakDGram application");
}
