// Fake Payment Interceptor
use tauri::{command, AppBuilder};

#[derive(Debug)]
pub struct PaymentData {
    pub provider: String,
    pub amount: f64,
}

#[command]
fn get_fake_payments() -> Vec<PaymentData> {
    vec![PaymentData { provider: "Fake".to_string(), amount: 10.0 }]
}

pub struct FakePaymentInterceptorPlugin;

impl FakePaymentInterceptorPlugin {
    pub fn init(_app: &mut AppBuilder) {
        println!("Fake Payment Interceptor initialized");
    }
}
