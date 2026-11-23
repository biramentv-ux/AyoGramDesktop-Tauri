use tauri::command;

#[command]
pub fn mobile_handle_version() -> &'static str {
    "2.0.0"
}

#[command]
pub fn mobile_handle_language() -> String {
    "Български".to_string()
}

#[cfg_target_os("android")]
pub mod android {
    use super::*;
    
    #[tauri::command]
    pub async fn android_handle_deep_link(url: String) -> Result<(), String> {
        println!("Android deep link received: {}", url);
        Ok(())
    }
}

#[cfg_target_os("ios")]
pub mod ios {
    use super::*;
    
    #[tauri::command]
    pub async fn ios_handle_share(text: String) -> Result<(), String> {
        println!("iOS shared text: {}", text);
        Ok(())
    }
}
