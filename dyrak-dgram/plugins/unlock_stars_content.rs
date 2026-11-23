// Unlock Stars Content
use tauri::{command, AppBuilder};

#[derive(Debug)]
pub struct StarContent {
    pub id: u64,
    pub name: String,
}

#[command]
fn get_unlocked_stars() -> Vec<StarContent> {
    vec![StarContent { id: 1, name: "Premium Badges".to_string() }]
}

pub struct UnlockStarsContentPlugin;

impl UnlockStarsContentPlugin {
    pub fn init(_app: &mut AppBuilder) {
        println!("Unlock Stars Content Plugin initialized");
    }
}
