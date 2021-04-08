#pragma once


#include <bits/stdc++.h>
#include "Stadium.cpp"
#include "PlaceToReserve.cpp"

class Ticket {
public:
    Match match = Match();
    int id;
public:
    Place place = Place(0, "0", 0, 0, 0);
public:
    bool isValid;
public:
    Ticket(int Id, Place Placeadd, Match Matchadd) {
        isValid = true;
        place = Placeadd;
        id = Id;
        match = Matchadd;
    }

public:
    void printTicket(Cashier cashier) {
        char* dt = ctime(&match.dateTime);
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Ticket ID in AccSys: " << id << endl;
        cout << "Cashier: " + cashier.getName();
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        if (place.IsAbonement())
            cout << "Abonement";
        else {
            cout << "Match: " << match.name << endl;
            cout << "MatchDate: " << dt;
        }
        cout << "Sector: " << place.sector << endl;
        cout << "Place ID: " << place.ID << endl;
        cout << "Place Row: " << place.row << endl;
        cout << "Place Number: " << place.number << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Price: " << place.price << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
};
