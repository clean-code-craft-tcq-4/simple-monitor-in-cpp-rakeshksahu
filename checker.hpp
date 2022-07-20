#ifndef CHECKER_HPP_
#define CHECKER_HPP_

#include <memory>
#include "MessageProvider.hpp"

class Checker
{
    public:
    std::shared_ptr<MessageProvider> msgProvider{nullptr};
    bool batteryIsApproachingThreshold(float temperature, float soc, float chargeRate);
    bool batteryIsOk(float temperature, float soc, float chargeRate);
};
#endif