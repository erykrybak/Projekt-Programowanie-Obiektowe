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
        Reservation(nextReservationId, guestId, roomNumber, from, to, now()));
    nextReservationId++;
    return nextReservationId - 1;
  } else {
    return -1;
  }
}

bool HotelSystem::cancelReservation(int guestId, int reservationID) {
  for (size_t i = 0; i < reservationList.size(); i++) {
    if (reservationID == reservationList[i].getId()) {
      if (reservationList[i].getGuestId() != guestId)
        return false; // nie można anulować cudzej rezerwacji.
      if (reservationList[i].isCanceled())
        return true;
      if (reservationList[i].isCheckedIn())
        return false;
      for (size_t j = 0; j < guestList.size(); j++) {
        if (reservationList[i].getGuestId() == guestList[j].getId()) {
          guestList[j].addFee(reservationList[i].countCancellationFee(
              daysToCancel, cancellationFeeAmount, now()));
        }
      }
      reservationList[i].cancel();
      return true;
    }
  }
  return false;
}

bool HotelSystem::guestCheckIn(int rId) {
  for (size_t i = 0; i < reservationList.size(); i++) {
    if (rId == reservationList[i].getId()) {
      if (reservationList[i].isCheckedIn() || reservationList[i].isCanceled())
        return false;
      reservationList[i].checkIn(now());
      return true;
    }
  }
  return false;
}

int HotelSystem::guestCheckOut(int rId) {
  for (size_t i = 0; i < reservationList.size(); i++) {
    if (rId ==
        reservationList[i]
            .getId()) { // sprawdzamy czy istnieje rezerwacja o szukanym ID
      if (!reservationList[i].isCheckedIn()) { // nie da się wymeldować
                                               // niezameldowanego gościa
        return -1;
      }
      for (size_t j = 0; j < roomList.size(); j++) {
        if (roomList[j].getRoomNumber() ==
            reservationList[i].getRoomNumber()) { // szukanie pokoju na liście
                                                  // żeby przekazać go fakturze
          billList.push_back(Bill(
              nextBillId, roomList[j], reservationList[i].getServicesTotal(),
              reservationList[i].getStartDate(),
              reservationList[i].getEndDate(),
              now())); // Stworzenie faktury i dodanie jej do listy
          nextBillId++;
          reservationList.erase(reservationList.begin() +
                                i); // Usuwamy rezerwację po wymeldowaniu
          return nextBillId - 1;    // funkcja zwraca ID utworzonej faktury.
        }
      }
      return -1;
    }
  }
  return -1;
}

void HotelSystem::addRoom(Room room) { roomList.push_back(room); }

void HotelSystem::addGuest(Guest guest) { guestList.push_back(guest); }

void HotelSystem::newService(AdditionalService service) {
  additionalServicesList.push_back(service);
}

bool HotelSystem::addService(int reservationID, std::string serviceName) {
  for (std::size_t i = 0; i < reservationList.size(); i++) {
    if (reservationList[i].getId() == reservationID) {
      if (reservationList[i].isCanceled())
        return false;
      for (std::size_t j = 0; j < additionalServicesList.size(); j++) {
        if (additionalServicesList[j].getName() == serviceName) {
          reservationList[i].addService(additionalServicesList[j]);
          return true;
        }
      }
    }
  }
  return false;
}

std::vector<std::string> HotelSystem::getServiceNames() {
  std::vector<std::string> serviceNames;
  for (std::size_t i = 0; i < additionalServicesList.size(); i++) {
    serviceNames.push_back(additionalServicesList[i].getName());
  }
  return serviceNames;
}

double HotelSystem::getBillTotal(int billId) const {
  for (std::size_t i = 0; i < billList.size(); i++) {
    if (billId == billList[i].getId()) {
      return billList[i].getTotal();
    }
  }
  return -1;
}

const Guest *HotelSystem::findGuest(int id) const {
  for (size_t i = 0; i < guestList.size(); i++) {
    if (guestList[i].getId() == id) {
      return &guestList[i];
    }
  }
  return nullptr;
}

void HotelSystem::setCurrentTime(time_t t) { fakeNow = t; }

time_t HotelSystem::now() const {
  if (fakeNow != 0) {
    return fakeNow;
  } else {
    return time(nullptr);
  }
}

bool HotelSystem::displayGuestReservations(int guestId) const {
  bool found = false;
  for (size_t i = 0; i < reservationList.size(); i++) {
    if (reservationList[i].getGuestId() == guestId) {
      reservationList[i].displayData();
      found = true;
    }
  }
  return found;
}
