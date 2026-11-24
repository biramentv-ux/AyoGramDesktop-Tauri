pragma once

#include "PluginInterface.h"

class MK_FuckPaymentsPlugin : public PluginInterface {
public:
    MK_FuckPaymentsPlugin();
    
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
    bool enabled;
    void bypassPaymentRequest(std::string& request);
};