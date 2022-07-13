#include "BMSParam.hpp"

BMSParam::~BMSParam() = default;

float BMSParam::getMinApproachingLevel(float minValue)
{
    return minValue + ((minValue * EARLY_WARNING_PERCENTAGE) / 100);
}

float BMSParam::getMaxApproachingLevel(float maxValue)
{
    return maxValue - ((maxValue * EARLY_WARNING_PERCENTAGE) / 100);
}