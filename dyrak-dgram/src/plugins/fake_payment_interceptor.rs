// FakePaymentInterceptor - Payment interception plugin
pub struct FakePaymentInterceptorPlugin;

impl FakePaymentInterceptorPlugin {
    pub fn init() -> Self {
        println!("FakePaymentInterceptorPlugin initialized");
        Self
    }
    
    pub fn get_name(&self) -> &'static str {
        "FakePaymentInterceptor"
    }
}

impl Default for FakePaymentInterceptorPlugin {
    fn default() -> Self {
        Self::init()
    }
}
