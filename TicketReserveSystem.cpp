
#pragma once

#include <bits/stdc++.h>
#include "ITicketReserveSystem.h"

using namespace std;

static map<pair<int, int>, int> res;
static map<int, int> resAbonem;

class TicketReserveSystem : ITicketReserveSystem {
public:
    Stadium stadium;
public:
    TicketReserveSystem() {
        stadium = Stadium();
    }

    void writePlace(int matchID) override {
        for (auto iter = stadium.matchCatalogue.matches[matchID].places.begin();
             iter != stadium.matchCatalogue.matches[matchID].places.end(); iter++) {
            cout << "[ID] : " << iter-> ID << "  " << iter-> sector << "[Row] : " << iter-> row << "[Number] : " << iter-> number << " ";
            if (res[make_pair(matchID, iter -> ID)] == 1) {
                cout << "[reserved]" << endl;
            } else {
                cout << "[free]" << endl;
            }
        }
    }

    vector<Place> getAbonementPlaces() override {
        return stadium.abonementPlaces;
    }

    MatchCatalogue GetMatchCatalogue() override {
        return stadium.GetMatchCatalogue();
    }

    Place GetPlace(PlaceToReserve plc) override {
        return stadium.matchCatalogue.matches[plc.MatchID].places[plc.PlaceID];
    }

    Match GetMatch(int plc) override {
        return stadium.matchCatalogue.matches[plc];
    }

    Place GetAbonement(int plcID) override {
        return stadium.abonementPlaces[plcID];
    }

    bool AreMatchesAvailable() override {
        return true;
    }

    bool ArePlacesAvailable(int mcID) override {
        return true;
    }

    bool IsPlaceAvailable(PlaceToReserve plcRv) override {
        if (res[make_pair(plcRv.MatchID, plcRv.PlaceID)] == 1)
            return false;
        return true;
    }

    void ReservePlaceTemporarily(PlaceToReserve plcRv, int duration, time_t currentTime) override {
        res[make_pair(plcRv.MatchID, plcRv.PlaceID)] = 1;
    }

    void FreePlace(int MatchID, int PlaceID) override {
        res[make_pair(MatchID, PlaceID)] = 0;
    }

    void ReservePlace(int MatchID, int PlaceID) override {
        res[make_pair(MatchID, PlaceID)] = 1;
    }

    void ReservePlace(PlaceToReserve plcRv) override {
        res[make_pair(plcRv.MatchID, plcRv.PlaceID)] = 1;
    }

    bool AreAbonementsAvailable() override {
        return true;
    }

    bool IsAbonementAvailable(int plcID) override {
        if (resAbonem[plcID] == 1)
            return false;
        return true;
    }

    void ReserveAbonementTemporarily(int plcID, time_t curTime, int duration) override {
        resAbonem[plcID] = 1;
    }

    void FreePlace(int plcRv) override {
        resAbonem[plcRv] = 0;
    }

    void ReservePlace(int plcRv) override {
        resAbonem[plcRv] = 1;
    }

    Cashier AddCashier(string name) override {
        return stadium.staff.AddCashier(name);
    }

    void WriteAbonementPlaces() override {
        for (auto iter = stadium.abonementPlaces.begin();
             iter != stadium.abonementPlaces.end(); iter++) {
            cout << "[ID] : " << iter-> ID << "  " << iter-> sector << "[Row] : " << iter-> row << "[Number] : " << iter-> number << " ";
            if (resAbonem[iter -> ID] == 1) {
                cout << "[reserved]" << endl;
            } else {
                cout << "[free]" << endl;
            }
        }
    }

};