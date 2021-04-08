#pragma once

#include <bits/stdc++.h>
#include "Stadium.cpp"
#include "PlaceToReserve.cpp"

class ITicketReserveSystem {
public:
    virtual MatchCatalogue GetMatchCatalogue() = 0;
    virtual Place GetPlace(PlaceToReserve plc)= 0;
    virtual Place GetAbonement(int plcID)= 0;
    virtual bool AreMatchesAvailable()= 0;
    virtual bool AreAbonementsAvailable()= 0;
    virtual bool ArePlacesAvailable(int mcID)= 0;
    virtual bool IsAbonementAvailable(int plcID)= 0;
    virtual bool IsPlaceAvailable(PlaceToReserve plcRv)= 0;
    virtual void ReserveAbonementTemporarily(int plcID, time_t curTime, int duration)= 0;
    virtual void ReservePlaceTemporarily(PlaceToReserve plcRv, int duration, time_t currentTime)= 0;
    virtual void ReservePlace(PlaceToReserve plcRv)= 0;
    virtual void FreePlace(int MatchID, int PlaceID)= 0;
    virtual void ReservePlace(int plcRv)= 0;
    virtual void FreePlace(int plcRv)= 0;
    virtual Cashier AddCashier(string name)= 0;
    virtual void WriteAbonementPlaces()= 0;
    virtual vector<Place> getAbonementPlaces()= 0;
    virtual Match GetMatch(int plc) = 0;
    virtual void writePlace(int matchID) = 0;
    virtual void ReservePlace(int MatchID, int PlaceID) = 0;
};