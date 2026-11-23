mod plugins;

use tauri::{
    AppBuilder, CustomMenuItem, Menu, MenuItem, Submenu,
};
use plugins::mk_fuck_payments::MKFuckPaymentsPlugin;
use plugins::fake_payment_interceptor::FakePaymentInterceptorPlugin;
use plugins::unlock_stars_content::UnlockStarsContentPlugin;
use plugins::local_telegram_premium::LocalTelegramPremiumPlugin;
use plugins::spotydown::SpotyDownPlugin;

fn main() {
    let _app = AppBuilder::new()
        .setup(|app| {
            // Initialize plugins
            MKFuckPaymentsPlugin::init(app);
            FakePaymentInterceptorPlugin::init(app);
            UnlockStarsContentPlugin::init(app);
            LocalTelegramPremiumPlugin::init(app);
            SpotyDownPlugin::init(app);
            Ok(())
        })
        .build()
        .expect("Failed to build app");
}
