// Plugin system modules
mod mk_fuck_payments;
mod fake_payment_interceptor;
mod unlock_stars_content;
mod local_telegram_premium;
mod spotydown;

/// Initialize all plugins
pub fn init_plugins() {
    mk_fuck_payments::init();
    fake_payment_interceptor::init();
    unlock_stars_content::init();
    local_telegram_premium::init();
    spotydown::init();
}

/// Get plugin list
pub fn get_plugins() -> Vec<&'static str> {
    vec![
        "MKFuckPaymentsPlugin",
        "FakePaymentInterceptorPlugin", 
        "UnlockStarsContentPlugin",
        "LocalTelegramPremiumPlugin",
        "SpotyDownPlugin"
    ]
}
