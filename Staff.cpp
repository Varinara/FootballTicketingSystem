#pragma once

#include <bits/stdc++.h>
#include "Cashier.cpp"

using namespace std;

class Staff {
public:
    vector<Cashier> cashiers;

public:
    Staff() {
        cashiers = vector<Cashier>();
    }

public:
    Cashier AddCashier(string cashierName) {
        cashiers.emplace_back(Cashier(cashiers.size(), cashierName));
        return cashiers.back();
    }
};