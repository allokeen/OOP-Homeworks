#pragma once
#include "Observer.h"

class ObserverImpl : public Observer {
public:
    virtual void remember(std::string question, std::string answer);
    std::string answer(std::string question) const;

private:
    std::map<std::string, std::string> answers;
};
