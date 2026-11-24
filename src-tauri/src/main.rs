// dyrakDGram Main Application
// Telegram-based desktop client with premium features and Spotify integration

mod plugins;
use plugins::init_plugins;

fn main() {
    println!("dyrakDGram - Telegram Desktop Client with Premium Features");
    
    // Initialize all plugins
    init_plugins();
}


