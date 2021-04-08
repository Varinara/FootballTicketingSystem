cmake_minimum_required(VERSION 3.10)
project(UML)

set(CMAKE_CXX_STANDARD 11)

add_executable(UML Cashier.cpp Staff.cpp MatchCatalogue.cpp Place.cpp Match.cpp Stadium.cpp PlaceToReserve.cpp TicketReserveSystem.cpp ITicketReserveSystem.h AcquireAbonement.cpp AcquireTicket.cpp IBank.h Bank.cpp Ticket.cpp ReturnMoney.cpp Payment.cpp Receipt.cpp IAccountingService.h AccountingService.cpp ReturnPurchase.cpp Terminal.cpp main.cpp)