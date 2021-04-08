#pragma once

#include <bits/stdc++.h>
#include "Stadium.cpp"
#include "PlaceToReserve.cpp"
#include "Bank.cpp"
#include "Payment.cpp"

class Receipt {
    Payment payment;
    Match match;
    Place place = Place(0, "0", 0, 0, 0);
    int transactionID;
public:
    Receipt(Payment Payment, Place Place, int trID, Match matchadd) {
        transactionID = trID;
        payment = Payment;
        place = Place;
        match = matchadd;
    }
public:
    void printReceipt(Cashier cashier) {
        cout << "------------------------------" << endl;
        cout << "Transaction ID in AccSys: " << transactionID << endl;
        cout << "Cashier: " << cashier.getName() << endl;
        payment.dateTime = time(0);
        char* dt = ctime(&payment.dateTime);

        cout << "DateTime: " << dt;
        cout << "Payment Method: " << payment.paymentMethod << endl;
        cout << "______________________________" << endl;
        if (place.IsAbonement())
            cout << "Abonement" << endl;
        else {
             dt = ctime(&match.dateTime);
            cout << "Match: " << match.name << ' ' << dt;
        }
        cout << "Sector: " << place.sector << endl;
        cout << "Place ID: " << place.ID << endl;
        cout << "Place Row: " << place.row << endl;
        cout << "Place Number: " << place.number << endl;
        cout << "______________________________" << endl;
        cout << "Price: " << place.price << endl;
        cout << "------------------------------" << endl;
    }
};
