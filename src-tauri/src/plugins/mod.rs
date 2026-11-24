// Plugins module for dyrakDGram
// All premium features and Spotify integration with full plugin system

use tauri::{command, Manager};

/// Initialize all plugins for dyrakDGram with full configuration
pub fn init_plugins() {
    // Initialize each plugin
    fake_payment_interceptor::init_fake_payment_interceptor();
    mk_fuck_payments::init_mk_fuck_payments();
    unlock_stars_content::init_unlock_stars_content();
    local_telegram_premium::init_local_telegram_premium();
    spotydown::init_spotydown();
    
    println!("All dyrakDGram plugins initialized successfully");
}


