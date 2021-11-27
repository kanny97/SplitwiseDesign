#pragma once
#include "Split.h"
#include "User.h"

class ExactSplit : public Split
{
public:
    ExactSplit(User user, double amount);
};