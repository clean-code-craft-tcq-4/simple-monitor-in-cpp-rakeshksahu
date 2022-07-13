#ifndef BMS_PARAM_HPP_
#define BMS_PARAM_HPP_

#include <iostream>
#include "MessageProvider.hpp"

#define EARLY_WARNING_PERCENTAGE 5 

using namespace std;

class BMSParam
{
    public:
    BMSParam() = default;
    virtual ~BMSParam();
    virtual bool checkIfToleranceApproaching() = 0;
    virtual bool checkWithinRange() = 0;
    protected:
    float getMinApproachingLevel(float minValue, float maxValue);
    float getMaxApproachingLevel(float minValue, float maxValue);
    bool checkIfApproachingThreshold(float value, float minValue, float maxValue);
};

class Temperature : public BMSParam
{
    public:
    explicit Temperature(float value, MessageProvider* msgProvider) : m_value(value), m_msgProvider(msgProvider) {} 
    bool checkIfToleranceApproaching() override;
    bool checkWithinRange() override;
    private:
    float m_value {0};
    MessageProvider *m_msgProvider {nullptr};
    const float MIN_TEMP {0};
    const float MAX_TEMP {45};
};

class SOC : public BMSParam
{
    public:
    explicit SOC(float value, MessageProvider* msgProvider) : m_value(value), m_msgProvider(msgProvider) {} 
    bool checkIfToleranceApproaching() override;
    bool checkWithinRange() override;
    private:
    float m_value {0};
    MessageProvider *m_msgProvider {nullptr};
    const float MIN_SOC {20};
    const float MAX_SOC {80};
};

class ChargeRate : public BMSParam
{
    public:
    explicit ChargeRate(float value, MessageProvider* msgProvider) : m_value(value), m_msgProvider(msgProvider) {} 
    bool checkIfToleranceApproaching() override;
    bool checkWithinRange() override;
    private:
    float m_value {0};
    MessageProvider *m_msgProvider {nullptr};
    const float MIN_CHARGE_RATE {0};
    const float MAX_CHARGE_RATE {.8};
};

#endif