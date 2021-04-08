#pragma once

#include <bits/stdc++.h>
#include "Place.cpp"
#include <ctime>


using namespace std;

class Match {
public:
    vector<Place> places;
    int ID;
    string name;
    time_t dateTime;

public: Match(){

    };
public:
    Match(int newID, string newName, vector<Place> newPlaces, time_t date) {
        dateTime = date;
        ID = newID;
        name = newName;
        places = newPlaces;
    }

public:
    string GetName() {
        return name;
    }

public:
    void writeMatch() {
        char* dt = ctime(&dateTime);
        time_t date = time(0);
        int i = dateTime - date;

        if (i < 0)
            return;
        cout << "[ID] : " << ID << ' ' << name << " [dateTime]: " << dt;
    }
};