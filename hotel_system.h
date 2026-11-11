#pragma once
#include "guest.h"
#include "reservation.h"
#include "room.h"
#include <ctime>
#include <vector>

class HotelSystem {
private:
  std::vector<Room> roomList;
  std::vector<Reservation> reservationList;
  std::vector<Guest> guestList;
  int nextReservationId = 0;

public:
  std::vector<int> checkAvailability(std::time_t startDate,
                                     std::time_t endDate);
  int makeReservation(int guestId, time_t from, time_t to, int roomNumber);
  bool cancelReservation(int reservationID);
  bool guestCheckIn(int rId);
  bool guestCheckOut(int rId);
  void addRoom(Room room);
  void addGuest(Guest guest);
};
