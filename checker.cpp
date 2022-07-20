#include <assert.h>
#include <iostream>
#include "checker.hpp"
#include "BMSParam.hpp"

using namespace std;

bool Checker::batteryIsApproachingThreshold(float temperature, float soc, float chargeRate)
{ 
  std::shared_ptr<BMSParam> temp(new Temperature(temperature, msgProvider.get())); 
  std::shared_ptr<BMSParam> stateOfCharge(new SOC(soc, msgProvider.get()));
  std::shared_ptr<BMSParam> rateOfCharge(new ChargeRate(chargeRate, msgProvider.get()));
  return (temp->checkIfToleranceApproaching() || stateOfCharge->checkIfToleranceApproaching() || rateOfCharge->checkIfToleranceApproaching());
}

bool Checker::batteryIsOk(float temperature, float soc, float chargeRate)
{
  std::shared_ptr<BMSParam> temp(new Temperature(temperature, msgProvider.get())); 
  std::shared_ptr<BMSParam> stateOfCharge(new SOC(soc, msgProvider.get()));
  std::shared_ptr<BMSParam> rateOfCharge(new ChargeRate(chargeRate, msgProvider.get()));
  return (temp->checkWithinRange() && stateOfCharge->checkWithinRange() && rateOfCharge->checkWithinRange());
}
