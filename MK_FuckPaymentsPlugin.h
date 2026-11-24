#pragma once
#include "PluginInterface.h"

class MK_FuckPaymentsPlugin : public PluginInterface {
public:
    const char* getPluginName() const override { return "MK_FuckPaymentsPlugin"; }
    void initialize() override;
    void cleanup() override;
    
    // Override payment handling
    virtual bool handlePaymentRequest(const PaymentRequest& request) override;
    virtual void onPaymentReceived(const PaymentResponse& response) override;
    
private:
    bool enabled;
};
