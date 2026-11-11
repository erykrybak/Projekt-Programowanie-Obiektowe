#pragma once
#include "hotel_system.h"
#include "person.h"
#include "reservation.h"

class HotelReceptionist : public Person {
private:
  int workerID;

public:
  HotelReceptionist(std::string name, std::string surname, int id, int workerID);
  void guestCheckIn(int reservationId, HotelSystem &system);
  void guestCheckOut(int reservationId, HotelSystem &system);
};
