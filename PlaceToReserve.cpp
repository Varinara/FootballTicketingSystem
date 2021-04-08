#pragma once

#include <bits/stdc++.h>

using namespace std;

class PlaceToReserve {
public:
    int MatchID;
public:
    int PlaceID;
public:
    PlaceToReserve(int mcID, int pcID) {
        MatchID = mcID;
        PlaceID = pcID;
    }
};