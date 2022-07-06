#include <assert.h>
#include <iostream>
using namespace std;

bool findIfNotInRange(float value, float min, float max)
{
    return (value < min || value > max);
}

bool checkTemperature(float temperature)
{
  bool result {true};
  if(findIfNotInRange(temperature, 0, 45)) {
    cout << "Temperature out of range!\n";
    result = false;
  }
  return result;   
}

bool checkSoc(float soc)
{
  bool result {true};
  if(findIfNotInRange(soc, 20, 80)) {
    cout << "State of Charge out of range!\n";
    result = false;
  }
  return result;
}

bool checkChargeRate(float chargeRate)
{
  bool result {true};
  if(findIfNotInRange(chargeRate, 0, 0.8)) {
    cout << "Charge Rate out of range!\n";
    result = false;
  }
  return result;
}

bool batteryIsOk(float temperature, float soc, float chargeRate)
{
  return checkTemperature(temperature) && checkSoc(soc) && checkChargeRate(chargeRate);
}
