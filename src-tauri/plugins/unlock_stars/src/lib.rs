// Unlock Stars Content Plugin - Unlock premium content

use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct UnlockStarsState {
    pub enabled: bool,
    pub unlocked_content: Vec<String>,
}

impl Default for UnlockStarsState {
    fn default() -> Self {
        Self {
            enabled: false,
            unlocked_content: vec![
                "Telegram Premium stickers".to_string(),
                "Custom profile emoji".to_string(),
                "Advanced chat features".to_string(),
            ],
        }
    }
}

pub fn initialize() -> (String, String, String) {
    (
        "Unlock Stars Content Plugin",
        "1.0.0",
        "Unlocks premium content and features for Telegram users"
    )
}

pub fn enable_unlock(state: &mut UnlockStarsState) -> Result<(), String> {
    state.enabled = true;
    Ok(())
}

pub fn toggle(state: &mut UnlockStarsState) {
    state.enabled = !state.enabled;
}

pub fn add_content(state: &mut UnlockStarsState, content: String) {
    if !state.unlocked_content.contains(&content) {
        state.unlocked_content.push(content);
    }
}

pub fn list_unlocked(state: &UnlockStarsState) -> Vec<String> {
    state.unlocked_content.clone()
}