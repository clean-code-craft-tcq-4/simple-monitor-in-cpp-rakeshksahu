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
    float getMinApproachingLevel(float minValue);
    float getMaxApproachingLevel(float maxValue);
};

class Temperature : public BMSParam
{
    public:
    explicit Temperature(float value, MessageProvider* msgProvider) : m_value(value), m_msgProvider(msgProvider) {} 
    bool checkIfToleranceApproaching() override
    {
        bool result = (((MIN_TEMP < m_value) && (m_value < getMinApproachingLevel(MIN_TEMP)))
         || ((getMaxApproachingLevel(MAX_TEMP) < m_value) && (m_value < MAX_TEMP)));
        if (result)
        {
            std::cout << m_msgProvider->getWarningMessageForTemp() << std::endl;
        }
        return result;
    }
    bool checkWithinRange() override
    {
        bool result = ((MIN_TEMP < m_value) && (m_value < MAX_TEMP));
        if (result == false)
        {
            std::cout << m_msgProvider->getErrorMessageForTemp() << std::endl;
        }
        return result;
    }
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
    bool checkIfToleranceApproaching() override
    {
        bool result = (((MIN_SOC < m_value) && (m_value < getMinApproachingLevel(MIN_SOC)))
         || ((getMaxApproachingLevel(MAX_SOC) < m_value) && (m_value < MAX_SOC)));
        if (result)
        {
            cout << m_msgProvider->getWarningMessageForSOC() << endl;
        }
        return result;
    }
    bool checkWithinRange() override
    {
        bool result = ((MIN_SOC < m_value) && (m_value < MAX_SOC));
        if (result == false)
        {
            cout << m_msgProvider->getWarningMessageForSOC() << endl;
        }
        return result;
    }
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
    bool checkIfToleranceApproaching() override
    {
        bool result = (((MIN_CHARGE_RATE < m_value) && (m_value < getMinApproachingLevel(MIN_CHARGE_RATE)))
         || ((getMaxApproachingLevel(MAX_CHARGE_RATE) < m_value) && (m_value < MAX_CHARGE_RATE)));
        if (result)
        {
            cout << m_msgProvider->getWarningMessageForCR() << endl;
        }
        return result;
    }
    bool checkWithinRange() override
    {
        bool result = ((MIN_CHARGE_RATE < m_value) && (m_value < MAX_CHARGE_RATE));
        if (result == false)
        {
            cout << m_msgProvider->getErrorMessageForCR() << endl;
        }
        return result;
    }
    private:
    float m_value {0};
    MessageProvider *m_msgProvider {nullptr};
    const float MIN_CHARGE_RATE {0};
    const float MAX_CHARGE_RATE {.8};
};

#endif