#pragma once

#include <bits/stdc++.h>

using namespace std;

class Cashier {
    int ID;
    string name;
public:
    Cashier(int id, string Name) {
        ID = id;
        name = Name;
    }

public:
    string getName() {
        return name;
    }

public:
    int getID() {
        return ID;
    }
};