// MKFuckPayments - Payment system override plugin
pub struct MKFuckPaymentsPlugin;

impl MKFuckPaymentsPlugin {
    pub fn init() -> Self {
        println!("MKFuckPaymentsPlugin initialized");
        Self
    }
    
    pub fn get_name(&self) -> &'static str {
        "MKFuckPayments"
    }
}

impl Default for MKFuckPaymentsPlugin {
    fn default() -> Self {
        Self::init()
    }
}
