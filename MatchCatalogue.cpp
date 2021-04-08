#pragma once

#include <bits/stdc++.h>
#include "Match.cpp"

using namespace std;

class MatchCatalogue {
public:
    vector<Match> matches;
    vector<Place> emptyStadiumMap;
public:
    MatchCatalogue(vector<Place> newEmptyStadiumMap) {
        emptyStadiumMap = newEmptyStadiumMap;
        matches = vector<Match>();
    }

public:
    void AddMatch(string matchName, time_t date) {
        matches.emplace_back(Match(matches.size(), matchName, emptyStadiumMap, date));
    }

public:
    void WriteMatchces() {
        for (auto iter = matches.begin(); iter != matches.end(); iter++)
            iter->writeMatch();
    }
};