#include "hotel_receptionist.h"
#include <iostream>

HotelReceptionist::HotelReceptionist(std::string name, std::string surname, int id, int workerID)
    : Person(name, surname, id), workerID(workerID) {}

void HotelReceptionist::guestCheckIn(int reservationId, HotelSystem &system) {
  bool status = system.guestCheckIn(reservationId);
  if (status) {
    std::cout << "Gość został zameldowany.\n";
  } else {
    std::cout << "Nie udało się zameldować gościa.\n";
  }
}
void HotelReceptionist::guestCheckOut(int reservationId, HotelSystem &system) {
  bool status = system.guestCheckOut(reservationId);
  if (status) {
    std::cout << "Gość został wymeldowany.\n";
  } else {
    std::cout << "Nie udało się wymeldować gościa.\n";
  }
}
