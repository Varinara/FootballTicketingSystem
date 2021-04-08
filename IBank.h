#pragma once

#include <bits/stdc++.h>
#include "Stadium.cpp"
#include "PlaceToReserve.cpp"
#include "Ticket.cpp"

class IBank {
    virtual bool CardIsValidForTransaction(double price, string cardNumber, string expDate, string cvc) = 0;

    virtual bool CardIsValidForTransaction(string cardNumber, string expDate, string cvc) = 0;

    virtual void ConcludePayment(double price, string cardNumber, string expDate, string cvc) = 0;

    virtual void ConcludeReturn(double price, string cardNumber, string expDate, string cvc) = 0;

    virtual bool isReturnViable(Ticket ticket) = 0;
};
