#pragma once
#include "hotel_system.h"
#include "person.h"
#include "reservation.h"

class HotelReceptionist : public Person {
private:
  int workerID;

public:
  HotelReceptionist(const std::string &name, const std::string &surname, int id, int workerID);
  void displayData() override;
  void guestCheckIn(int reservationId, HotelSystem &system);
  void guestCheckOut(int reservationId, HotelSystem &system);
};
