#pragma once

#include <bits/stdc++.h>
#include "Stadium.cpp"
#include "PlaceToReserve.cpp"
#include "Bank.cpp"

class ReturnMoney {
    Bank bank;
public:
    ReturnMoney() {
        bank = Bank();
    }

    bool isReturnViable(Ticket ticket) {
        return bank.isReturnViable(ticket);
    }

public:
    void concludeReturn(Ticket ticket) {
        if (isReturnViable(ticket)) {
            cout << "How do you want your money to be returned? cash / card" << endl;
            string paymentChoice;
            cin >> paymentChoice;
            if (paymentChoice == "card") {
                cout << "Card number:" << endl;
                string cardNumber;
                cin >> cardNumber;
                cout << "Exp. date: " << endl;
                string expDate;
                cin >> expDate;
                cout << "CVC : " << endl;
                string cvc;
                cin >> cvc;
                if (bank.CardIsValidForTransaction(cardNumber, expDate, cvc))
                    bank.ConcludeReturn(ticket.place.price, cardNumber, expDate, cvc);
                else {
                    cout << "The card is not valid for this transaction";
                    exit;
                }
                return;
            }
            if (paymentChoice == "cash") {
                cout << "Returning: " << ticket.place.price << endl;
                return;
            }
            cout << "There is no such payment method";
            exit(0);
        } else {
            cout << "Return is not viable";
            exit(0);
        }
    }
};