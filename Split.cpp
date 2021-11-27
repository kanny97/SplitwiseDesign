#include "Split.h"

Split::Split()
{
    this -> user = user;
}

Split::Split(User user)
{
    this -> user = user;
}

User Split::getUser()
{
    return user;
}

void Split::setUser(User user)
{
    this -> user = user;
}

double Split::getAmount()
{
    return amount;
}

void Split::setAmount(double amount)
{
    this -> amount = amount;
}


