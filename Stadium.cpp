#pragma once


#include <bits/stdc++.h>
#include "Staff.cpp"
#include "MatchCatalogue.cpp"

using namespace std;

class Stadium {

public:
    vector<Place> abonementPlaces;
public:
    vector<Place> emptyStadiumMap;
public:
    MatchCatalogue matchCatalogue = MatchCatalogue(emptyStadiumMap);
public:
    Staff staff;

public:
    Stadium() {
        srand(time(NULL));
        emptyStadiumMap = vector<Place>();
        for (char ssector = 'A'; ssector <= 'C'; ssector++) {
            for (int i = 1; i < 4; i++)
                for (int j = 1; j < 4; j++) {
                    string ss = "Sector:";
                    ss = ss + ssector + " ";
                    emptyStadiumMap.emplace_back(Place(emptyStadiumMap.size(), ss, i, j, false));
                }
        }
        matchCatalogue = MatchCatalogue(emptyStadiumMap);
        for (int i = 0; i < 5; i++) {
            string s1 = "Team";
            s1 = s1 + " " + char('a' + i);
            string s2 = "Team";
            s2 = s2 + " " + char(('a' + (i - '0')));
            s1 = s1 + " vs " + s2;
            time_t date = time(0);
            int time_random = int(rand() % int(1e9))+int(1e8);
            matchCatalogue.AddMatch(s1, date + time_random);
        }

        abonementPlaces = vector<Place>();
        for (int i = 1; i < 4; i++)
            for (int j = 1; j < 4; j++) {
                abonementPlaces.emplace_back(Place(abonementPlaces.size(), "Fan Sector ", i, j, true));
            }
        staff = Staff();
    }

public:
    MatchCatalogue GetMatchCatalogue() {
        return matchCatalogue;
    }
};