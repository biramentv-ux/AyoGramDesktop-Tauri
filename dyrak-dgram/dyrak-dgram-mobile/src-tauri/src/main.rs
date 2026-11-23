mod plugins;

use tauri::command;
use tauri::AppBuilder;
use tauri::Manager;

#[command]
pub async fn handle_fake_payment(amount: f64, currency: String) -> Result<String, String> {
    plugins::fake_payment_interceptor::handle_fake_payment(amount, currency)
        .await
        .map(|r| r.message)
        .map_err(|e| e.to_string())
}

#[command]
pub fn handle_mk_fuck_payments() -> Result<String, String> {
    plugins::mk_fuck_payments::handle_mk_fuck_payments()
        .map(|r| r.message)
        .map_err(|e| e.to_string())
}

#[command]
pub fn handle_unlock_stars_content() -> Result<String, String> {
    plugins::unlock_stars_content::handle_unlock_stars_content()
        .map(|r| r.message)
        .map_err(|e| e.to_string())
}

#[command]
pub fn handle_local_telegram_premium() -> Result<String, String> {
    plugins::local_telegram_premium::handle_local_telegram_premium()
        .map(|r| r.message)
        .map_err(|e| e.to_string())
}

#[command]
pub async fn handle_spotydown(track_id: String) -> Result<String, String> {
    plugins::spotydown::handle_spotydown(track_id)
        .await
        .map(|r| format!("{} - {}", r.message, r.download_url.unwrap_or("N/A".to_string())))
        .map_err(|e| e.to_string())
}

fn main() {
    tauri::Builder::default()
        .setup(|app| {
            println!("dyrakDGram initialized successfully");
            Ok(())
        })
        .invoke_handler(tauri::generate_handler![
            handle_fake_payment,
            handle_mk_fuck_payments,
            handle_unlock_stars_content,
            handle_local_telegram_premium,
            handle_spotydown,
        ])
        .build(tauri::generate_context!())
        .expect("Error while building dyrakDGram");
}
