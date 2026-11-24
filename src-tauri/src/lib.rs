// dyrakDGram Plugins Library
// All premium features and Spotify integration with full plugin system

pub mod plugins;

use tauri::{Manager, App};

/// Initialize all plugins for dyrakDGram
pub fn init_plugins(app: &mut App) {
    // Initialize plugin system
    println!("Initializing dyrakDGram plugins...");
    
    // Initialize each plugin
    plugins::init_plugins();
    
    // Register plugin commands
    app.setup(|_app, _api| {
        println!("dyrakDGram plugin setup complete");
        Ok(())
    });
}

/// Plugin registry for dyrakDGram
pub struct PluginRegistry {
    plugins: Vec<String>,
}

impl PluginRegistry {
    pub fn new() -> Self {
        Self {
            plugins: vec![
                "FakePaymentInterceptor".to_string(),
                "MKFuckPayments".to_string(),
                "UnlockStarsContent".to_string(),
                "LocalTelegramPremium".to_string(),
                "SpotyDown".to_string(),
            ],
        }
    }
    
    pub fn list_plugins(&self) -> &[String] {
        &self.plugins
    }
}

impl Default for PluginRegistry {
    fn default() -> Self {
        Self::new()
    }
}
