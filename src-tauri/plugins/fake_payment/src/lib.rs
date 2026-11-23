use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct GhostModeState {
    pub invisible_typing: bool,
    pub hide_read_receipts: bool,
}

impl Default for GhostModeState {
    fn default() -> Self {
        Self {
            invisible_typing: true,
            hide_read_receipts: true,
        }
    }
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct StreamModeState {
    pub enabled: bool,
    pub quality: String,
}

impl Default for StreamModeState {
    fn default() -> Self {
        Self {
            enabled: true,
            quality: "1080p".into(),
        }
    }
}

