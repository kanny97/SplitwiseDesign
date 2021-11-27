#include "Expense.h"

Expense::Expense()
{

}

Expense::Expense(User paidBy, double amount, vector<Split> splits)
{
    this -> paidBy = paidBy;
    this -> amount = amount;
    this -> splits = splits;    
}
string Expense::getId()
{
    return id;
}
void Expense::setId(string id)
{
    this -> id = id;
}
User Expense::getPaidBy()
{
    return paidBy;
}
void Expense::setPaidBy(User user)
{
    this -> paidBy = paidBy;
}
double Expense::getAmount()
{
    return amount;
}
void Expense::setAmount(double amount)
{
    this -> amount = amount;
}
vector<Split> Expense::getSplits()
{
    return splits;
}
void Expense::setSplits(vector<Split> splits)
{
    this -> splits = splits;
}