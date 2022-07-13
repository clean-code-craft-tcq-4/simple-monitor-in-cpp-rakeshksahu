#include "checker.hpp"
#include <assert.h>
using namespace std;

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  assert(batteryIsOk(30, 70, 0.1) == true);
  assert(batteryIsOk(30, 70, 0.9) == false);

  assert(batteryIsApproachingThreshold(1, 70, 0.7) == true);
  assert(batteryIsApproachingThreshold(25, 78, 0.7) == true);
  assert(batteryIsApproachingThreshold(25, 70, 0.7) == false);
  assert(batteryIsApproachingThreshold(25, 70, 0.79) == true);
}