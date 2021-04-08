#pragma once

#include <bits/stdc++.h>
#include "TicketReserveSystem.cpp"

using namespace std;

class AcquireTicket {
    int ReserveDuration;
    TicketReserveSystem TR;
    time_t currentTime;
public:
    PlaceToReserve plc = PlaceToReserve(0, 0);
public:
    AcquireTicket(TicketReserveSystem TicketReserveSys) {
        TR = TicketReserveSys;
        ReserveDuration = 1000000;
        currentTime = 0;
    }

public:
    void initialize() {
        if (TR.AreMatchesAvailable()) {
            MatchCatalogue MC = TR.GetMatchCatalogue();
            cout << "[Available Matches]" << endl;
            MC.WriteMatchces();
            cout << "Write the match ID:" << endl;
            int chosenMatchID;
            cin >> chosenMatchID;
            if (chosenMatchID > MC.matches.size()) {
                cout << "Operation Cancelled" << endl;
                abort();
            }
            if (TR.ArePlacesAvailable(chosenMatchID)) {
                cout << "[Available Places for this Match]" << endl;
                TR.writePlace(chosenMatchID);
                cout << "Write the place ID: " << endl;
                int chosenPlaceID;
                cin >> chosenPlaceID;
                if (chosenPlaceID > MC.matches[chosenMatchID].places.size()) {
                    cout << "Operation Cancelled" << endl;
                    exit(0);
                }
                plc = PlaceToReserve(chosenMatchID, chosenPlaceID);
                if (TR.IsPlaceAvailable(plc)) {
                    TR.ReservePlaceTemporarily(plc, ReserveDuration, currentTime);
                } else {
                    cout << "Sorry, but this place is no longer available." << endl;
                    exit(0);
                }
            } else {
                cout << "Places for this Match are not available.";
                exit(0);
            }
        } else {
            cout << "Matches are not available at this moment.";
            exit(0);
        }
    }

public:
    void cancel(int match, int place) {
        TR.FreePlace(match, place);
    }

public:
    void conclude(int match, int place) {
        TR.ReservePlace(match, place);
    }
};