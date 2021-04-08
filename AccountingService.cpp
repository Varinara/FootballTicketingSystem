#pragma once

#include <bits/stdc++.h>
#include "Stadium.cpp"
#include "PlaceToReserve.cpp"
#include "Payment.cpp"
#include "IAccountingService.h"

static map<int, int> returnMon;

class AccountingService : IAccountingService {
    vector<tuple<int, Payment, Place>> TransactionsDB;
    vector<Ticket> TicketsDB;
public:
    AccountingService() {
        TransactionsDB = vector<tuple<int, Payment, Place >>();
        TicketsDB = vector<Ticket>();
    }

    int AddCompletedTransaction(Payment payment, Place place) override {
        tuple<int, Payment, Place> transaction = tuple<int, Payment, Place>(TransactionsDB.size(), payment, place);
        cout << TransactionsDB.size() << endl;
        TransactionsDB.emplace_back(transaction);
        cout << TransactionsDB.size() << endl;
        return get<0>(transaction);
    }

    Ticket AddNewTicket(Place place, Match match) override {
        TicketsDB.emplace_back(Ticket(TicketsDB.size(), place, match));
        return TicketsDB[TicketsDB.size() - 1];
    }

    vector<Ticket> GetTickets() override {
        return TicketsDB;
    }
};