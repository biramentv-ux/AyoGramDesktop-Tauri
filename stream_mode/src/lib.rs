use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct StreamState {
    pub enabled: bool,
    pub quality: String,
    pub bitrate: u32,
}

impl Default for StreamState {
    fn default() -> Self {
        Self { enabled: false, quality: "720p".into(), bitrate: 2500 }
    }
}

pub fn toggle(state: &mut StreamState) {
    state.enabled = !state.enabled;
}
