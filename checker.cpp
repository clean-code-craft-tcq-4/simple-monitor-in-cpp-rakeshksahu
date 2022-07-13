#include <assert.h>
#include <iostream>
#include "checker.hpp"

using namespace std;

bool findIfNotInRange(float value, float min, float max)
{
    return (value < min || value > max);
}

bool checkTemperature(float temperature)
{
  bool result {true};
  if(findIfNotInRange(temperature, MIN_TEMP, MAX_TEMP)) {
    cout << "Temperature out of range!\n";
    result = false;
  }
  return result;   
}

bool checkSoc(float soc)
{
  bool result {true};
  if(findIfNotInRange(soc, MIN_SOC, MAX_SOC)) {
    cout << "State of Charge out of range!\n";
    result = false;
  }
  return result;
}

bool checkChargeRate(float chargeRate)
{
  bool result {true};
  if(findIfNotInRange(chargeRate, MIN_CRATE, MAX_CRATE)) {
    cout << "Charge Rate out of range!\n";
    result = false;
  }
  return result;
}

bool batteryIsOk(float temperature, float soc, float chargeRate)
{
  return checkTemperature(temperature) && checkSoc(soc) && checkChargeRate(chargeRate);
}
