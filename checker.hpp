#ifndef CHECKER_HPP_

#define CHECKER_HPP_

#include <iostream>
using namespace std;

#define MIN_TEMP    0 
#define MAX_TEMP    45
#define MIN_SOC     20  
#define MAX_SOC     80
#define MIN_CRATE   0
#define MAX_CRATE   .8

bool checkTemperature(float temperature);
bool checkSoc(float soc);
bool checkChargeRate(float chargeRate);
bool batteryIsOk(float temperature, float soc, float chargeRate);
bool findIfNotInRange(float value, float min, float max);

#endif