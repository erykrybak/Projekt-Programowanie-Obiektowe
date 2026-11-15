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
  std::vector<AdditionalService> additionalServiceList; 
  int nextReservationId = 0;

public:
  std::vector<int> checkAvailability(std::time_t startDate, std::time_t endDate);
  int makeReservation(Guest* guest, std::time_t from, std::time_t to, Room* room);
  bool cancelReservation(int reservationID);
  bool guestCheckIn(int reservationID);
  bool guestCheckOut(int reservationID);
  void addRoom(Room room);
  void addGuest(Guest guest);
  void addAdditionalService(AdditionalService additionalService);
};
