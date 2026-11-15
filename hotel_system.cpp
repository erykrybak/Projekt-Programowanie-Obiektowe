#include "hotel_system.h"
#include <algorithm>
using namespace std;

vector<int> HotelSystem::checkAvailability(time_t startDate, time_t endDate) {
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

int HotelSystem::makeReservation(Guest* guest, time_t from, time_t to, Room* room) {
    if (guest == nullptr || room == nullptr || from >= to) {
      return -1;
    }
    vector<int> currentlyAvailableRooms = checkAvailability(from, to);
    int roomNumber = room->getRoomNumber();
    bool isRoomAvailable = (find(currentlyAvailableRooms.begin(), currentlyAvailableRooms.end(), roomNumber) != currentlyAvailableRooms.end());

    if (isRoomAvailable) {
        reservationList.push_back (Reservation(nextReservationId, guest, room, from, to));
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
      reservationList[i].checkIn();
      return true;
    }
  }
  return false;
}
bool HotelSystem::guestCheckOut(int rId) {
  for (size_t i = 0; i < reservationList.size(); i++) {
    if (rId == reservationList[i].getId()) {
      if (!reservationList[i].isCheckedIn()) {
        return false;
      }
      reservationList.erase(reservationList.begin() + i);
      return true;
    }
  }
  return false;
}
void HotelSystem::addRoom(Room room){
roomList.push_back(room);
}

void HotelSystem::addGuest(Guest guest){
guestList.push_back(guest);
}

void HotelSystem::addAdditionalService(AdditionalService additionalService) {
    additionalServiceList.push_back(additionalService);
}
