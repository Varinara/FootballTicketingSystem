#pragma once


#include <bits/stdc++.h>
#include "Stadium.cpp"
#include "PlaceToReserve.cpp"
#include "TicketReserveSystem.cpp"
#include "Payment.cpp"
#include "IAccountingService.h"
#include "AcquireTicket.cpp"
#include "Receipt.cpp"
#include "AcquireAbonement.cpp"
#include "AccountingService.cpp"
#include "ReturnPurchase.cpp"
#include "ReturnMoney.cpp"

class Terminal {
public:
    void Main() {
        TicketReserveSystem tras = TicketReserveSystem();

        cout << "Type in the cashier name: " << endl;
        string cashierName;
        cin >> cashierName;
        cout << "" << endl;
        Cashier cashier = tras.AddCashier(cashierName);
        AccountingService accounting = AccountingService();
        int calc = 0;
        while (calc++ < 8) {

            cout << "Available operations: " << endl;
            cout << "[1] Buy Ticket." << endl;
            cout << "[2] Buy Abonement." << endl;
            cout << "[3] Return Purchased Item." << endl;
            cout << "[AnyOther] Cancel" << endl;

            cout << "ID of Desired Operation: " << endl;
            string desiredOperation;
            cin >> desiredOperation;
            cout << "" << endl;
            if (desiredOperation == "1") {
                AcquireTicket acquireTicketProc = AcquireTicket(tras);
                acquireTicketProc.initialize();
                Payment payment = Payment();
                Place place = tras.GetPlace(acquireTicketProc.plc);
                Match match = tras.GetMatch(acquireTicketProc.plc.MatchID);
                payment.writePayment(place, match);
                cout << "Do you accept? y/n" << endl;
                string response;
                cin >> response;
                cout << "" << endl;
                if (response == "y") {
                    cout << "How do you want to pay? card/cash" << endl;
                    string payChoice;
                    cin >> payChoice;
                    cout << "" << endl;
                    payment.conclude(payChoice, place);
                }
                if (payment.successful()) {
                    acquireTicketProc.conclude(match.ID, place.ID);
                    int transactionID = accounting.AddCompletedTransaction(payment, place);
                    Receipt receipt = Receipt(payment, place, transactionID, match);
                    Ticket ticket = accounting.AddNewTicket(place, match);
                    cout << "THE RECEIPT:" << endl;
                    receipt.printReceipt(cashier);
                    cout << "" << endl;
                    cout << "THE TICKET:" << endl;
                    ticket.printTicket(cashier);
                    cout << "" << endl;
                } else {
                    acquireTicketProc.cancel(match.ID, place.ID);
                    cout << "Transaction Failed" << endl;
                    exit(0);
                }
            } else if (desiredOperation == "2") {
                AcquireAbonement acquireAbonementProc = AcquireAbonement(tras);
                acquireAbonementProc.initialize();
                Place place = tras.GetAbonement(acquireAbonementProc.chosenPlaceID);
                Match match = Match();

                Payment payment = Payment();
                payment.writePayment(place, match);
                cout << "Do you accept? y/n" << endl;
                string response;
                cin >> response;
                cout << "" << endl;
                if (response == "y") {
                    cout << "How do you want to pay? card/cash" << endl;
                    string payChoice;
                    cin >> payChoice;
                    cout << "" << endl;
                    payment.conclude(payChoice, place);
                }
                if (payment.successful()) {
                    acquireAbonementProc.conclude();
                    int transactionID = accounting.AddCompletedTransaction(payment, place);
                    Receipt receipt = Receipt(payment, place, transactionID, match);
                    Ticket ticket = accounting.AddNewTicket(place, match);
                    cout << "THE RECEIPT:" << endl;
                    receipt.printReceipt(cashier);
                    cout << "" << endl;
                    cout << "THE ABONEMENT:" << endl;
                    ticket.printTicket(cashier);
                    cout << "" << endl;
                } else {
                    acquireAbonementProc.cancel();
                    cout << "Transaction Failed" << endl;
                    exit(0);
                }
            } else if (desiredOperation == "3") {
                cout << "Type in the TicketID specified on your product" << endl;
                cout << "TicketID: " << endl;
                int id;
                cin >> id;
                ReturnPurchase returnPR = ReturnPurchase(accounting, tras);
                ReturnMoney returnMN = ReturnMoney();
                if (returnPR.tIsValid(id)) {
                    Ticket ticket = returnPR.GetTicket(id);
                    returnMN.concludeReturn(ticket);
                    if (ticket.place.IsAbonement())
                        returnPR.cancel(ticket.place, ticket.match);
                    else
                        returnPR.cancel(ticket.place);
                    ticket.isValid = false;
                    cout << "The purchase was successfully returned." << endl;
                } else {
                    cout << "This Ticket is invalid" << endl;
                    exit(0);
                }
            } else {
                exit(0);
            }
        }
    }
};
