#include "hotel_receptionist.h"
#include <iostream>
using namespace std;

HotelReceptionist::HotelReceptionist(const string& name, const string& surname, int id, int workerID)
    : Person(name, surname, id), workerID(workerID) {}

void HotelReceptionist::displayData() {
    cout << "Imię: " << name << "\nNazwisko: " << surname << "\nID pracownika: " << workerID << endl;
}

void HotelReceptionist::guestCheckIn(int reservationId, HotelSystem &system) {
  bool status = system.guestCheckIn(reservationId);
  if (status) {
    cout << "Gość został zameldowany.\n";
  } else {
    cout << "Nie udało się zameldować gościa.\n";
  }
}
void HotelReceptionist::guestCheckOut(int reservationId, HotelSystem &system) {
  bool status = system.guestCheckOut(reservationId);
  if (status) {
    cout << "Gość został wymeldowany.\n";
  } else {
    cout << "Nie udało się wymeldować gościa.\n";
  }
}
