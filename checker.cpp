#include <assert.h>
#include <iostream>
#include <memory>
#include "checker.hpp"
#include "BMSParam.hpp"
#include "MessageProvider.hpp"
using namespace std;

bool batteryIsApproachingThreshold(float temperature, float soc, float chargeRate)
{
  std::shared_ptr<MessageProvider> engMsgProvider(new EnglishMessageProvider()); 
  std::shared_ptr<BMSParam> temp(new Temperature(temperature, engMsgProvider.get())); 
  std::shared_ptr<BMSParam> stateOfCharge(new SOC(soc, engMsgProvider.get()));
  std::shared_ptr<BMSParam> rateOfCharge(new ChargeRate(chargeRate, engMsgProvider.get()));
  return (temp->checkIfToleranceApproaching() || stateOfCharge->checkIfToleranceApproaching() || rateOfCharge->checkIfToleranceApproaching());
}

bool batteryIsOk(float temperature, float soc, float chargeRate)
{
  std::shared_ptr<MessageProvider> grMsgProvider(new GermanMessageProvider()); 
  std::shared_ptr<BMSParam> temp(new Temperature(temperature, grMsgProvider.get())); 
  std::shared_ptr<BMSParam> stateOfCharge(new SOC(soc, grMsgProvider.get()));
  std::shared_ptr<BMSParam> rateOfCharge(new ChargeRate(chargeRate, grMsgProvider.get()));
  return (temp->checkWithinRange() && stateOfCharge->checkWithinRange() && rateOfCharge->checkWithinRange());
}
