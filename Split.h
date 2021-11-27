#pragma once
#include "User.h"
class Split
{
private:
    User user;
public:
    double amount;
    Split();
    Split(User user);
    User getUser();
    void setUser(User user);
    double getAmount();
    void setAmount(double amount);
};