#include <assert.h>
#include <iostream>
using namespace std;

bool findIfNotInRange(float value, float min, float max)
{
    return (value < min || value > max);
}
bool batteryIsOk(float temperature, float soc, float chargeRate) {
  if(findIfNotInRange(temperature, 0, 45)) {
    cout << "Temperature out of range!\n";
    return false;
  } else if(findIfNotInRange(soc, 20, 80)) {
    cout << "State of Charge out of range!\n";
    return false;
  } else if(findIfNotInRange(chargeRate ,0, 0.8)) {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
