#pragma once

#include <bits/stdc++.h>

using namespace std;

class Place {
public:
    bool abonement;
public:
    string sector;
public:
    int ID;
public:
    int row;
public:
    int number;
public:
    double price;

public:
    Place(int newID, string newSector, int newRow, int newNumber, bool Abonement) {
        ID = newID;
        sector = newSector;
        row = newRow;
        number = newNumber;

        if (abonement) {
            price = 500;
        } else {
            price = 50;
        }

        abonement = Abonement;
    }

public:
    double GetPrice() {
        return price;
    }

public:
    bool IsAbonement() {
        return abonement;
    }

public:
    int GetID() {
        return ID;
    }

};