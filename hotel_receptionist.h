#pragma once
#include "person.h"
#include "reservation.h"

class HotelReceptionist: private Person{
    private:
        int workerID;
    public:
        void guestCheckIn(Reservation reservation);
        void guestCheckOut(Reservation reservation);
};
