// UnlockStarsContent - Premium content unlock plugin
pub struct UnlockStarsContentPlugin;

impl UnlockStarsContentPlugin {
    pub fn init() -> Self {
        println!("UnlockStarsContentPlugin initialized");
        Self
    }
    
    pub fn get_name(&self) -> &'static str {
        "UnlockStarsContent"
    }
}

impl Default for UnlockStarsContentPlugin {
    fn default() -> Self {
        Self::init()
    }
}
