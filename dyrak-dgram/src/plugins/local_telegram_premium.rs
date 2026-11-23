// LocalTelegramPremium - Premium features plugin
pub struct LocalTelegramPremiumPlugin;

impl LocalTelegramPremiumPlugin {
    pub fn init() -> Self {
        println!("LocalTelegramPremiumPlugin initialized");
        Self
    }
    
    pub fn get_name(&self) -> &'static str {
        "LocalTelegramPremium"
    }
}

impl Default for LocalTelegramPremiumPlugin {
    fn default() -> Self {
        Self::init()
    }
}
