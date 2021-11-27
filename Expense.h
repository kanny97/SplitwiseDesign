#pragma once
#include "User.h"
#include "Split.h"
#include <bits/stdc++.h>
using namespace std;

class Expense
{
private:
    string id;
    User paidBy;
    double amount;
    vector<Split> splits;
public:
    Expense();
    Expense(User paidBy, double amount, vector<Split> splits);
    string getId();
    void setId(string id);
    User getPaidBy();
    void setPaidBy(User user);
    double getAmount();
    void setAmount(double amount);
    vector<Split> getSplits();
    void setSplits(vector<Split> splits);
};