#pragma once
#include "User.h"
#include "Expense.h"
#include "ExpenseType.h"
#include "Split.h"
#include<bits/stdc++.h>
using namespace std;

class ExpenseManager
{
public:
    unordered_map<string, User> userMap;
    vector<Expense> expenses;
    unordered_map<string, unordered_map<string, double>> balanceSheet;

    void addUser(User user);
    void addExpense(ExpenseType expenseType, string paidBy, double amount, vector<Split> splits);
    void showBalances();
    void showBalances(string userid);
    void printBalance(string user1, string user2, double amount);
};