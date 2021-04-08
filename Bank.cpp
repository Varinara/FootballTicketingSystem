#pragma once

#include <bits/stdc++.h>
#include "Stadium.cpp"
#include "PlaceToReserve.cpp"
#include "IBank.h"


class Bank : IBank {
public:
    Bank() {

    }

    bool isReturnViable(Ticket ticket) override {
        return true;
    }

    bool CardIsValidForTransaction(string cardNumber, string expDate, string cvc) override {
        return true;
    }

    bool CardIsValidForTransaction(double price, string cardNumber, string expDate, string cvc) override {
        return false;
    }

    void ConcludePayment(double price, string cardNumber, string expDate, string cvc) override {
        return;
    }

    void ConcludeReturn(double price, string cardNumber, string expDate, string cvc) override {
        return;
    }
};
