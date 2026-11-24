pragma once

#include "PluginInterface.h"

class FakePaymentInterceptorPlugin : public PluginInterface {
public:
    FakePaymentInterceptorPlugin();
    
    std::string getName() const override;
    std::string getDescription() const override;
    std::vector<std::string> getFeatures() const override;
    bool isEnabled() const override;
    void enable() override;
    void disable() override;
    int getPriority() const override;
    bool shouldIntercept(std::string request) override;
    std::string interceptAndModify(std::string request) override;

private:
    std::string fakePaymentResponse(std::string response);
};