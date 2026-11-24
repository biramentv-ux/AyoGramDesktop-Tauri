#pragma once
#include "PluginInterface.h"

class FakePaymentInterceptorPlugin : public PluginInterface {
public:
    const char* getPluginName() const override { return "FakePaymentInterceptorPlugin"; }
    void initialize() override;
    void cleanup() override;
    
    // Intercept and fake payments
    virtual bool interceptPayment(const PaymentRequest& request) override;
    virtual PaymentResponse generateFakePayment(const PaymentRequest& request) override;
    
private:
    bool enabled;
    std::vector<std::string> fakePaymentMethods;
};
