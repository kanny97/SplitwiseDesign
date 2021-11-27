#pragma once
#include "Split.h"
#include "User.h"

class PercentSplit : public Split
{
private:
    double percentage;
public:
    PercentSplit();
    PercentSplit(User user, double percentage, double amount);
    double get_percentage();
    void set_percentage(double percentage);
};