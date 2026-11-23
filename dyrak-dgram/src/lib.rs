pub mod plugins;

use tauri::{App, Window};

/// Plugin initialization structure
pub struct PluginInit {
    pub name: &'static str,
    pub init_fn: &'static str,
}

/// Main application entry point for plugins
pub fn init_plugins(app: &mut App) {
    plugins::mk_fuck_payments::init(app);
    plugins::fake_payment_interceptor::init(app);
    plugins::unlock_stars_content::init(app);
    plugins::local_telegram_premium::init(app);
    plugins::spotydown::init(app);
}

/// Get application version
pub fn get_version() -> &'static str {
    "2.0.0"
}
