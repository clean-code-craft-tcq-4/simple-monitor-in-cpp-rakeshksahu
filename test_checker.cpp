#include "checker.hpp"
#include <assert.h>
using namespace std;

int main() {
  Checker checker;
  //checker.msgProvider = std::make_shared<EnglishMessageProvider>();
  checker.msgProvider = std::make_shared<GermanMessageProvider>();
  assert(checker.batteryIsOk(0, 70, 0.7) == false);
  assert(checker.batteryIsOk(25, 70, 0.7) == true);
  assert(checker.batteryIsOk(50, 70, 0.7) == false);
  assert(checker.batteryIsOk(25, 10, 0.7) == false);
  assert(checker.batteryIsOk(25, 85, 0.5) == false);
  assert(checker.batteryIsOk(30, 70, 0.0) == false);
  assert(checker.batteryIsOk(30, 70, 0.1) == true);

  assert(checker.batteryIsApproachingThreshold(1, 70, 0.7) == true);
  assert(checker.batteryIsApproachingThreshold(44, 70, 0.7) == true);
  assert(checker.batteryIsApproachingThreshold(40, 70, 0.7) == false);
  assert(checker.batteryIsApproachingThreshold(50, 70, 0.7) == false);
  assert(checker.batteryIsApproachingThreshold(25, 22, 0.7) == true);
  assert(checker.batteryIsApproachingThreshold(25, 78, 0.7) == true);
  assert(checker.batteryIsApproachingThreshold(25, 13, 0.7) == false);
  assert(checker.batteryIsApproachingThreshold(25, 85, 0.7) == false);
  assert(checker.batteryIsApproachingThreshold(25, 40, 0.7) == false);
  assert(checker.batteryIsApproachingThreshold(25, 70, 0.7) == false);
  assert(checker.batteryIsApproachingThreshold(25, 70, 0.79) == true);
  assert(checker.batteryIsApproachingThreshold(25, 70, 0.01) == true);
  assert(checker.batteryIsApproachingThreshold(25, 70, 0.0) == false);
  assert(checker.batteryIsApproachingThreshold(25, 70, 0.9) == false);
}