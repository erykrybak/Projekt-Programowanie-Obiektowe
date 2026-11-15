#pragma once
#include "guest.h"
#include "reservation.h"
#include "room.h"
#include <ctime>
#include <vector>
#include "additional_service.h"

class HotelSystem {
private:
  std::vector<Room> roomList;
  std::vector<Reservation> reservationList;
  std::vector<AdditionalService> additionalServicesList;
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
  void newService(AdditionalService service);
  bool addService(int reservationID, std::string serviceName);
  std::vector<std::string> getServiceNames();
};
