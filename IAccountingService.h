#pragma once

#include <bits/stdc++.h>
#include "Stadium.cpp"
#include "PlaceToReserve.cpp"
#include "Payment.cpp"

class IAccountingService {
    virtual int AddCompletedTransaction(Payment payment, Place place) = 0;

    virtual Ticket AddNewTicket(Place place, Match match) = 0;

    virtual vector<Ticket> GetTickets() = 0;
};