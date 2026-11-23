// SpotyDown - Music downloader plugin
pub struct SpotyDownPlugin;

impl SpotyDownPlugin {
    pub fn init() -> Self {
        println!("SpotyDownPlugin initialized");
        Self
    }
    
    pub fn get_name(&self) -> &'static str {
        "SpotyDown"
    }
}

impl Default for SpotyDownPlugin {
    fn default() -> Self {
        Self::init()
    }
}
