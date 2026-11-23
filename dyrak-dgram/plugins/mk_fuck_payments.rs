// MK Fuck Payments Plugin
use tauri::{command, AppBuilder};

#[command]
fn get_payment_methods() -> Vec<String> {
    vec!["Credit Card".to_string(), "PayPal".to_string()]
}

pub struct MKFuckPaymentsPlugin;

impl MKFuckPaymentsPlugin {
    pub fn init(_app: &mut AppBuilder) {
        println!("MK Fuck Payments Plugin initialized");
    }
}
