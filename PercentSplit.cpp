#include "PercentSplit.h"

PercentSplit::PercentSplit()
{

}

PercentSplit::PercentSplit(User user, double percentage, double amount):Split(user)
{
    this -> percentage = percentage;
    this -> amount = amount;
}

double PercentSplit::get_percentage()
{
    return percentage;
}

void PercentSplit::set_percentage(double percentage)
{
    this -> percentage = percentage;
}