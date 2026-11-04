#include "hotel_system.h"
#include <algorithm>
using namespace std;

vector<int> HotelSystem::checkAvailability(std::time_t startDate,
                                           std::time_t endDate) {
  vector<int> availableRooms;
  vector<int> bookedRooms;
  // zbieram numery pokoi na które jest rezerwacja w danym terminie
  for (size_t i = 0; i < reservationList.size(); i++) {
    if (reservationList[i].coversDate(startDate, endDate)) {
      bookedRooms.push_back(reservationList[i].getRoomNumber());
    }
  }
  // pokoje nie będące w liście zajętych dodawane są do listy dostępnych
  for (size_t i = 0; i < roomList.size(); i++) {
    bool isBooked = false;
    for (size_t j = 0; j < bookedRooms.size(); j++) {
      if (roomList[i].getRoomNumber() == bookedRooms[j]) {
        isBooked = true;
        break;
      }
    }
    if (!isBooked) {
      availableRooms.push_back(roomList[i].getRoomNumber());
    }
  }

  return availableRooms;
}

int HotelSystem::makeReservation(int guestId, time_t from, time_t to,
                                 int roomNumber) {
  vector<int> currentlyAvailableRooms = checkAvailability(from, to);
  // sprawdzenie czy gość istnieje, czy pokój jest dostępny i czy zakres dat
  // jest poprawny
  if (find_if(guestList.begin(), guestList.end(),
              [guestId](const Guest &g) { return g.getId() == guestId; }) !=
          guestList.end() &&
      find(currentlyAvailableRooms.begin(), currentlyAvailableRooms.end(),
           roomNumber) != currentlyAvailableRooms.end() &&
      from < to) {
    reservationList.push_back(
        Reservation(nextReservationId, guestId, roomNumber, from, to));
    nextReservationId++;
    return nextReservationId - 1;
  } else {
    return -1;
  }
}
bool HotelSystem::cancelReservation(int reservationID) {
  for (size_t i = 0; i < reservationList.size(); i++) {
    if (reservationID == reservationList[i].getId()) {
      reservationList[i].cancel();
      return true;
    }
  }
  return false;
}

bool HotelSystem::guestCheckIn(int rId) {
  for (size_t i = 0; i < reservationList.size(); i++) {
    if (rId == reservationList[i].getId()) {
      reservationList[i].checkedIn = true;
      return true;
    }
    return false;
  }
}
bool HotelSystem::guestCheckOut(int rId) {
  for (size_t i = 0; i < reservationList.size(); i++) {
    if (rId == reservationList[i].getId()) {
      if (!reservationList[i].checkedIn) {
        return false;
      }
      reservationList.erase(reservationList.begin() + i);
      return true;
    }
    return false;
  }
}
