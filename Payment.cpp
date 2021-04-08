#pragma once

#include <bits/stdc++.h>
#include "Stadium.cpp"
#include "PlaceToReserve.cpp"
#include "Bank.cpp"


class Payment {
    string status;
public:
    string paymentMethod;
public:
    time_t dateTime;
public:

    Payment() {
        time_t dateTime = time(0);
        status = "Started";
    }

public:

    bool successful() {
        if (status == "Success")
            return true;
        else
            return false;
    }

public:

    void writePayment(Place plc, Match match) {
        cout << "The place you've chosen is " << endl;
        if (plc.IsAbonement())
            cout << "an Abonement place" << endl;
        else
            cout << "a place for " << match.name << endl;
        cout << "[ID] : " << plc.ID << "  " << plc.sector << "[Row] : " << plc.row << "[Number] : " << plc.number << " " << endl;
        cout << "---------------------------------------- " << endl;
        cout << "Price: " << plc.GetPrice() << endl;
    }

public:
    void conclude(string paymentChoice, Place plc) {
        paymentMethod = paymentChoice;
        if (paymentChoice == "card") {
            cout << "Card number: " << endl;
            string cardNumber;
            cin >> cardNumber;
            cout << "Exp. date: " << endl;
            string expDate;
            cin >> expDate;
            cout << "CVC : " << endl;
            string cvc;
            cin >> cvc;
            Bank bank = Bank();
            if (bank.CardIsValidForTransaction(plc.GetPrice(), cardNumber, expDate, cvc)) {
                bank.ConcludePayment(plc.GetPrice(), cardNumber, expDate, cvc);
                status = "Success";
            } else {
                status = "Failed";
                cout << "This card is not valid to perform such transaction..." << endl;
            }
            return;
        }
        if (paymentChoice == "cash") {
            double sumNeeded = plc.GetPrice();
            double sumIns = 0;
            bool t = true;
            while (t) {
                cout << "Type in the amount of money you are giving or -1 to stop: " << endl;
                double cashIns;
                cin >> cashIns;
                cout << cashIns;
                if (cashIns > 0)
                    sumIns += cashIns;
                else
                    t = false;
            }
            if (sumIns >= sumNeeded) {
                double change = sumIns - sumNeeded;
                status = "Success";
                cout << "Transaction Successful" << endl;
                cout << "Your change: " << change << endl;
            } else {
                status = "Failed";
                cout << "Transaction Cancelled. Not enough money" << endl;
                cout << "Returning: " << sumIns << endl;
            }
            return;
        }
        cout << "This Payment Method is not suitable for thisterminal to operate" << endl;
    }
};
