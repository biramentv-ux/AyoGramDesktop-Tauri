mod fake_payment_interceptor;
mod mk_fuck_payments;
mod unlock_stars_content;
mod local_telegram_premium;
mod spotydown;

use tauri::{
    plugin::{Builder, Plugin, PluginStore},
    App, Runtime, Window,
};

fn main() {
    dyrakDGram::run();
}

// Fake Payment Interceptor Plugin
pub struct FakePaymentInterceptorPlugin;

impl<R: Runtime> Plugin<R> for FakePaymentInterceptorPlugin {
    const NAME: &'static str = "fake_payment_interceptor";
    const ID: &'static str = "fake_payment";

    fn build(&self, app: &App<R>) -> Option<Self> {
        None
    }

    fn on_event(&self, app: &App<R>, event: &tauri::RunEvent<'_>) {
        if let tauri::RunEvent::WindowEvent { label, event: _ } = event {
            println!("Fake payment intercepted: {}", label);
        }
    }
}

// MK Fuck Payments Plugin
pub struct MkkfPlugin;

impl<R: Runtime> Plugin<R> for MkkfPlugin {
    const NAME: &'static str = "mk_fuck_payments";
    const ID: &'static str = "mk_payments";

    fn build(&self, app: &App<R>) -> Option<Self> {
        None
    }

    fn on_event(&self, app: &App<R>, event: &tauri::RunEvent<'_>) {
        println!("MK Fuck Payments triggered");
    }
}

// Unlock Stars Content Plugin
pub struct UnlockStarsContentPlugin;

impl<R: Runtime> Plugin<R> for UnlockStarsContentPlugin {
    const NAME: &'static str = "unlock_stars_content";
    const ID: &'static str = "stars_content";

    fn build(&self, app: &App<R>) -> Option<Self> {
        None
    }

    fn on_event(&self, app: &App<R>, event: &tauri::RunEvent<'_>) {
        println!("Unlock Stars Content accessed");
    }
}

// Local Telegram Premium Plugin
pub struct LocalTelegramPremiumPlugin;

impl<R: Runtime> Plugin<R> for LocalTelegramPremiumPlugin {
    const NAME: &'static str = "local_telegram_premium";
    const ID: &'static str = "premium_features";

    fn build(&self, app: &App<R>) -> Option<Self> {
        None
    }

    fn on_event(&self, app: &App<R>, event: &tauri::RunEvent<'_>) {
        println!("Local Telegram Premium activated");
    }
}

// SpotyDown Music Downloader Plugin
pub struct SpotyDownPlugin;

impl<R: Runtime> Plugin<R> for SpotyDownPlugin {
    const NAME: &'static str = "spotydown";
    const ID: &'static str = "music_downloader";

    fn build(&self, app: &App<R>) -> Option<Self> {
        None
    }

    fn on_event(&self, app: &App<R>, event: &tauri::RunEvent<'_>) {
        println!("SpotyDown music download triggered");
    }
}
