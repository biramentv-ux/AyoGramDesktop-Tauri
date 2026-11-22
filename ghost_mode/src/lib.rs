use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct GhostState {
    pub invisible_typing: bool,
    pub hide_read_receipts: bool,
}

impl Default for GhostState {
    fn default() -> Self {
        Self { invisible_typing: false, hide_read_receipts: false }
    }
}

pub fn toggle(state: &mut GhostState, key: &str) {
    match key {
        "invisible_typing" => state.invisible_typing = !state.invisible_typing,
        "hide_read_receipts" => state.hide_read_receipts = !state.hide_read_receipts,
        _ => {}
    }
}
