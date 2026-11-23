use serde::{Deserialize, Serialize};

#[derive(Debug, Serialize, Deserialize)]
pub struct FakePaymentResult {
    pub success: bool,
    pub message: String,
    pub provider: String,
}

pub async fn handle_fake_payment(amount: f64, currency: String) -> Result<FakePaymentResult, String> {
    // Simulate payment processing with multiple providers
    let providers = vec!["TelegramStars", "Stripe", "PayPal", "CreditCard"];
    let selected_provider = &providers[std::time::SystemTime::now()
        .duration_since(std::time::UNIX_EPOCH)
        .map(|d| d.as_secs() as usize % providers.len())
        .unwrap_or(0)];
    
    Ok(FakePaymentResult {
        success: true,
        message: format!(
            "Fake payment of {} {} processed successfully via {}!",
            amount, currency, selected_provider
        ),
        provider: selected_provider.to_string(),
    })
}
