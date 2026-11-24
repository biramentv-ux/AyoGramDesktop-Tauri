#pragma once
#include "PluginInterface.h"

class UnlockStarsContentPlugin : public PluginInterface {
public:
    const char* getPluginName() const override { return "UnlockStarsContentPlugin"; }
    void initialize() override;
    void cleanup() override;
    
    // Unlock stars content
    virtual bool canUnlockStarsContent(const Message& message) override;
    virtual void unlockStarsContent(Message& message) override;
    
private:
    bool enabled;
    std::vector<std::string> premiumFeatures;
};
