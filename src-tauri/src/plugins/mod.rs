// Plugins module for dyrakDGram

pub mod fake_payment_interceptor;
pub mod mk_fuck_payments;
pub mod unlock_stars_content;
pub mod local_telegram_premium;
pub mod spotydown;

/// Re-export all plugin initialization functions
pub use fake_payment_interceptor::init_fake_payment_interceptor;
pub use mk_fuck_payments::init_mk_fuck_payments;
pub use unlock_stars_content::init_unlock_stars_content;
pub use local_telegram_premium::init_local_telegram_premium;
pub use spotydown::init_spotydown;

/// Initialize all plugins
pub fn init_plugins() {
    // Initialize each plugin
    init_fake_payment_interceptor();
    init_mk_fuck_payments();
    init_unlock_stars_content();
    init_local_telegram_premium();
    init_spotydown();
    
    println!("All dyrakDGram plugins initialized successfully");
}
