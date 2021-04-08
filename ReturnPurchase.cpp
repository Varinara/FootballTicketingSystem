#pragma once

#include <bits/stdc++.h>
#include "Stadium.cpp"
#include "PlaceToReserve.cpp"
#include "Payment.cpp"
#include "IAccountingService.h"
#include "TicketReserveSystem.cpp"
#include "AccountingService.cpp"

class ReturnPurchase {
    AccountingService accounting;
    TicketReserveSystem TR;
    vector<Ticket> tickets;
    int currentTime = 0;
public:
    ReturnPurchase(AccountingService accountingService, TicketReserveSystem tras) {
        tickets = accountingService.GetTickets();
        TR = tras;
    }

public:

    bool tIsValid(int id) {

        if (id < tickets.size() && returnMon[id] == 0)
            return tickets[id].isValid;
        else {
            cout << "This ticket does not exist." << endl;
            exit;
        }

    }

public:

    Place Identify(int id) {
        if (id < tickets.size())
            return tickets[id].place;
        else {
            cout << "This ticket does not exist." << endl;
            exit;
        }
    }

public:

    Ticket GetTicket(int id) {
        if (id < tickets.size())
            return tickets[id];
        else {
            cout << "This ticket does not exist." << endl;
            exit;
        }
    }

public: void cancel(Place place, Match match){
        TR.FreePlace(match.ID, place.ID);
    }

public: void cancel(Place place){
        TR.FreePlace(place.ID);
    }
};