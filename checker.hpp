#ifndef CHECKER_HPP_

#define CHECKER_HPP_

bool batteryIsApproachingThreshold(float temperature, float soc, float chargeRate);
bool batteryIsOk(float temperature, float soc, float chargeRate);

#endif