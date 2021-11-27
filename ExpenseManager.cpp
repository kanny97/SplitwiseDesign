#include "ExpenseManager.h"

void ExpenseManager::addUser(User user)
{
    userMap[user.get_id()] = user;
    balanceSheet[user.get_id()] = unordered_map<string,double>({});       
}
void ExpenseManager::addExpense(ExpenseType expenseType, string paidBy, double amount, vector<Split> splits)
{ 
    Expense expense(userMap[paidBy], amount, splits);
    if(expenseType == EQUAL)
    {
        int numUsers = splits.size();
        double individualAmount = round(amount * 100 / numUsers) / 100.0;
        for(int i = 0;i<splits.size();i++)
        {
            splits[i].setAmount(individualAmount);
        }

        splits[0].setAmount(individualAmount + (amount - (individualAmount * numUsers)));
        expense.setSplits(splits);
    }
    expenses.push_back(expense);//Push back this expense in the catalogue

    for(auto split : expense.getSplits())
    {
        string paidTo = split.getUser().get_id();
        double amount = split.getAmount();
        unordered_map<string, double> balances = balanceSheet[paidBy];
        if(balances.find(paidTo) == balances.end())//No entry for this pair
        {
            balanceSheet[paidBy][paidTo] = 0.0;
        }
        balanceSheet[paidBy][paidTo] += amount;
        balances = balanceSheet[paidTo];
        if(balances.find(paidBy) == balances.end())//No entry for this pair
        {
            balanceSheet[paidTo][paidBy] = 0.0;
        }
        balanceSheet[paidTo][paidBy] -= amount;
    }
}
void ExpenseManager::showBalances()
{
    bool isEmpty = true;

    for(auto balance : balanceSheet)
    {
        string user1 = balance.first;
        for(auto pairs : balance.second)
        {
            if(pairs.second > 0)
            {
                isEmpty = false;
                printBalance(user1, pairs.first, pairs.second);
            }
        }
    }
    if(isEmpty)
    cout<<"NO BALANCES"<<endl;
}
void ExpenseManager::showBalances(string userid)
{
    unordered_map<string, double> balances = balanceSheet[userid];
    if(balances.size() == 0)
    cout<<"NO BALANCES"<<endl;
    else
    {
        for(auto pair : balances)
        {
            if(pair.second != 0)
            {
                printBalance(userid, pair.first, pair.second);
            }
        }
    }
}
void ExpenseManager::printBalance(string user1, string user2, double amount)
{
    string username1 = userMap[user1].get_name();
    string username2 = userMap[user2].get_name();
    if(amount < 0)
    {
        cout<<username1<<" owes "<<username2<<":"<<abs(amount);
    }
    else if(amount > 0)
    {
        cout<<username2<<" owes "<<username1<<":"<<abs(amount);
    }
    cout<<endl;
}