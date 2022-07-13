#ifndef MESSAGE_PROVIDER_HPP_

#define MESSAGE_PROVIDER_HPP_

#include <string>

class MessageProvider
{
    public:
    virtual std::string getWarningMessageForTemp() = 0;
    virtual std::string getErrorMessageForTemp() = 0;
    virtual std::string getWarningMessageForCR() = 0;
    virtual std::string getErrorMessageForCR() = 0;
    virtual std::string getWarningMessageForSOC() = 0;
    virtual std::string getErrorMessageForSOC() = 0;
};

class EnglishMessageProvider : public MessageProvider
{
    public:
    std::string getWarningMessageForTemp() override { return "Temperature approaching threshold limit"; };
    std::string getErrorMessageForTemp() override { return "Temperature out of range"; };
    std::string getWarningMessageForCR() override { return "Charge rate approaching threshold limit"; };;
    std::string getErrorMessageForCR() override { return "Charge rate out of range"; };
    std::string getWarningMessageForSOC() override { return "SOC approaching threshold limit"; };;
    std::string getErrorMessageForSOC() override { return "SOC out of range"; };
};

class GermanMessageProvider : public MessageProvider
{
    public:
    std::string getWarningMessageForTemp() override { return "Temperatur nähert sich dem Grenzwert"; };
    std::string getErrorMessageForTemp() override { return "Temperatur außerhalb des Bereichs"; };
    std::string getWarningMessageForCR() override { return "Die Laderate nähert sich dem Schwellenwert"; };;
    std::string getErrorMessageForCR() override { return "Ladestrom außerhalb des Bereichs"; };
    std::string getWarningMessageForSOC() override { return "SOC nähert sich der Schwellengrenze"; };;
    std::string getErrorMessageForSOC() override { return "SOC außerhalb des Bereichs"; };
};
#endif