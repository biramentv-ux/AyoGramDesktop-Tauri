pub mod fake_payment_interceptor;
pub mod mk_fuck_payments;
pub mod unlock_stars_content;
pub mod local_telegram_premium;
pub mod spotydown;

// Mobile-specific plugins for Android/iOS builds
#[cfg.mobile]
pub mod mobile_plugin;
