#pragma once

#include <bits/stdc++.h>
#include "TicketReserveSystem.cpp"


using namespace std;

class AcquireAbonement {
    int tempReserveDuration;
    TicketReserveSystem TR;
    time_t currentTime;
public:
    int chosenPlaceID;
public:
    AcquireAbonement(TicketReserveSystem TicketReserveSys) {
        TR = TicketReserveSys;
        tempReserveDuration = 1000;
        currentTime = 0;
    }

public:
    void initialize() {
        if (TR.AreAbonementsAvailable()) {
            cout << "[Abonements available for Purchase]" << endl;
            vector<Place> abonementPlaces = TR.getAbonementPlaces();
            TR.WriteAbonementPlaces();
            cout << "Write the abonement ID: " << endl;
            cin >> chosenPlaceID;
            if (abs(chosenPlaceID) > abonementPlaces.size()) {
                cout << "Operation Cancelled" << endl;
                exit(0);
            }
            if (TR.IsAbonementAvailable(chosenPlaceID)) {
                TR.ReserveAbonementTemporarily(chosenPlaceID, currentTime, tempReserveDuration);
            } else {
                cout << "Sorry, but this abonement is no longer available." << endl;
                exit(0);
            }
        } else {
            cout << "Abonements are not available at this moment." << endl;
            exit(0);
        }
    }

public:
    void cancel() {
        TR.FreePlace(chosenPlaceID);
    }

public:
    void conclude() {
        TR.ReservePlace(chosenPlaceID);
    }
};