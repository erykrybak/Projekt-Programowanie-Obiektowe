#pragma once
#include "additional_service.h"
#include "bill.h"
#include "guest.h"
#include "reservation.h"
#include "room.h"
#include <ctime>
#include <vector>

class HotelSystem {
private:
  std::vector<Room> roomList;
  std::vector<Reservation> reservationList;
  std::vector<AdditionalService> additionalServicesList;
  std::vector<Guest> guestList;
  std::vector<Bill> billList;
  int nextReservationId = 0;
  int nextBillId = 0;
  const int daysToCancel = 2;
  const double cancellationFeeAmount = 50.0;
  std::time_t fakeNow = 0;

public:
  std::vector<int> checkAvailability(std::time_t startDate,
                                     std::time_t endDate);
  int makeReservation(int guestId, time_t from, time_t to, int roomNumber);
  bool cancelReservation(int guestId, int reservationID);
  bool guestCheckIn(int rId);
  int guestCheckOut(int rId);
  void addRoom(Room room);
  void addGuest(Guest guest);
  void newService(AdditionalService service);
  bool addService(int reservationID, std::string serviceName);
  std::vector<std::string> getServiceNames();
  double getBillTotal(int billId) const;
  const Guest *findGuest(int id) const;
  void setCurrentTime(std::time_t t);
  std::time_t now() const;
  bool displayGuestReservations(int guestId) const;
};
