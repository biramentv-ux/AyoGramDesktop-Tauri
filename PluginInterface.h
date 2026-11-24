#pragma once

#include <string>
#include <vector>

class PluginInterface {
public:
    virtual ~PluginInterface() = default;
    
    virtual std::string getName() const = 0;
    virtual std::string getDescription() const = 0;
    virtual std::vector<std::string> getFeatures() const = 0;
    virtual bool isEnabled() const = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual int getPriority() const = 0;
    virtual bool shouldIntercept(std::string request) = 0;
    virtual std::string interceptAndModify(std::string request) = 0;
};