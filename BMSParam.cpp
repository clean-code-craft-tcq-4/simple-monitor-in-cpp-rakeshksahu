#include "BMSParam.hpp"

BMSParam::~BMSParam() = default;

float BMSParam::getMinApproachingLevel(float minValue, float maxValue)
{
    return minValue + (((maxValue - minValue) * EARLY_WARNING_PERCENTAGE) / 100);
}

float BMSParam::getMaxApproachingLevel(float minValue, float maxValue)
{
    return maxValue - (((maxValue - minValue) * EARLY_WARNING_PERCENTAGE) / 100);
}

bool BMSParam::checkIfApproachingThreshold(float value, float minValue, float maxValue)
{
    return (((minValue < value) && (value < getMinApproachingLevel(minValue, maxValue)))
        || ((getMaxApproachingLevel(minValue, maxValue) < value) && (value < maxValue)));
}

bool Temperature::checkIfToleranceApproaching()
{
    bool result = checkIfApproachingThreshold(m_value, MIN_TEMP, MAX_TEMP);
    if (result)
    {
        std::cout << m_msgProvider->getWarningMessageForTemp() << std::endl;
    }
    return result;
}

bool Temperature::checkWithinRange()
{
    bool result = ((MIN_TEMP < m_value) && (m_value < MAX_TEMP));
    if (result == false)
    {
        std::cout << m_msgProvider->getErrorMessageForTemp() << std::endl;
    }
    return result;
}

bool SOC::checkIfToleranceApproaching()
{
    bool result = checkIfApproachingThreshold(m_value, MIN_SOC, MAX_SOC);
    if (result)
    {
        cout << m_msgProvider->getWarningMessageForSOC() << endl;
    }
    return result;
}
    
bool SOC::checkWithinRange()
{
    bool result = ((MIN_SOC < m_value) && (m_value < MAX_SOC));
    if (result == false)
    {
        cout << m_msgProvider->getWarningMessageForSOC() << endl;
    }
    return result;
}

bool ChargeRate::checkIfToleranceApproaching()
{
    bool result = checkIfApproachingThreshold(m_value, MIN_CHARGE_RATE, MAX_CHARGE_RATE);
    if (result)
    {
        cout << m_msgProvider->getWarningMessageForCR() << endl;
    }
    return result;
}

bool ChargeRate::checkWithinRange()
{
    bool result = ((MIN_CHARGE_RATE < m_value) && (m_value < MAX_CHARGE_RATE));
    if (result == false)
    {
        cout << m_msgProvider->getErrorMessageForCR() << endl;
    }
    return result;
}