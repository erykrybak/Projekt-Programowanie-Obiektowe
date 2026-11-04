#pragma once
#include "hotel_system.h"
#include "person.h"
#include "reservation.h"

class HotelReceptionist : public Person {
private:
  int workerID;

public:
  void guestCheckIn(int reservationId, HotelSystem &system);
  void guestCheckOut(int reservationId, HotelSystem &system);
};
