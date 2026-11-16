#include "hotel_receptionist.h"
#include <iostream>
using namespace std;

HotelReceptionist::HotelReceptionist(const string &name, const string &surname,
                                     int id, int workerID)
    : Person(name, surname, id), workerID(workerID) {}

void HotelReceptionist::displayData() const {
  Person::displayData();
  cout << "ID pracownika: " << workerID << endl;
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
  int billId = system.guestCheckOut(reservationId);
  if (billId >= 0) {
    cout << "Gość został wymeldowany.\nNr. faktury: " << billId
         << "\nKwota: " << system.getBillTotal(billId) << endl;
  } else {
    cout << "Nie udało się wymeldować gościa.\n";
  }
}
