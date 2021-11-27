#include "ExpenseManager.h"
#include "EqualSplit.h"
#include "ExactSplit.h"
#include "PercentSplit.h"

#include <iostream>
using namespace std;

vector<string> SplitStr(string str)
{
    vector<string> words;
    int n = str.size();
    string word = "";
    for(int i = 0;i<n;i++)
    {
        if(str[i] != ' ')
        word += str[i];
        else
        {
            words.push_back(word);
            word = "";
        }
    }
    words.push_back(word);
    return words;
}

int main()
{
    //Add initial users
    ExpenseManager expenseManager;
    expenseManager.addUser(User("u1", "User1", "gaurav@workat.tech", "9876543210"));
    expenseManager.addUser(User("u2", "User2", "sagar@workat.tech", "9876543210"));
    expenseManager.addUser(User("u3", "User3", "hi@workat.tech", "9876543210"));
    expenseManager.addUser(User("u4", "User4", "mock-interviews@workat.tech", "9876543210"));
    while(true)
    {
        string inputLine;
        getline(cin,inputLine);//Get the line from command prompt
        vector<string> commands = SplitStr(inputLine);
        string type = commands[0];
        if(type == "SHOW")
        {
            if(commands.size() == 1)//Only show which means show all balances
            expenseManager.showBalances();
            else
            {
                string userId = commands[1];
                expenseManager.showBalances(userId);
            }
        }
        else if(type == "END")
        break;
        else//Expense
        {
            string paidBy = commands[1];
            double amount = stod(commands[2]);
            int numUsers = stoi(commands[3]);
            string expenseType = commands[4 + numUsers];
            vector<Split> splits;
            if(expenseType == "EQUAL")
            {
                for(int i = 0;i<numUsers;i++)
                {
                    string userId = commands[4 + i];
                    splits.push_back(EqualSplit(expenseManager.userMap[userId]));
                }
                expenseManager.addExpense(ExpenseType::EQUAL, paidBy, amount, splits);
            }
            else if(expenseType == "EXACT")
            {
                for(int i = 0;i<numUsers;i++)
                {
                    string userId = commands[4 + i];
                    double amount = stod(commands[5 + numUsers + i]);
                    splits.push_back(ExactSplit(expenseManager.userMap[userId], amount));
                }
                expenseManager.addExpense(ExpenseType::EXACT, paidBy, amount, splits);
            }
            else if(expenseType == "PERCENT")
            {
                for(int i = 0;i<numUsers;i++)
                {
                    string userId = commands[4 + i];
                    double percentage = stod(commands[5 + numUsers + i]);
                    double splitAmount = (percentage * amount) / 100.0;
                    splits.push_back(PercentSplit(expenseManager.userMap[userId], percentage, splitAmount));
                }
                expenseManager.addExpense(ExpenseType::PERCENT, paidBy, amount, splits);
            }
        }
    }        
}