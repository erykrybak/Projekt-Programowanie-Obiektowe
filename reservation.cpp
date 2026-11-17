#include "reservation.h"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

static string formatDate(time_t t) {
  char buffer[11];
  strftime(buffer, sizeof(buffer), "%d.%m.%Y", localtime(&t));
  return buffer;
}

double Reservation::countCancellationFee(int daysToCancel,
                                         double cancellationFeeAmount,
                                         std::time_t now) const {
  double daysLeft = difftime(startDate, now) / 86400.0;
  if (daysLeft < daysToCancel) {
    return cancellationFeeAmount;
  }
  return 0;
}

int Reservation::getRoomNumber() const { return roomNumber; }

bool Reservation::coversDate(time_t checkStartDate, time_t checkEndDate) const {
  return !canceled && startDate < checkEndDate && checkStartDate < endDate;
}

Reservation::Reservation(int id, int guestId, int roomNumber,
                         std::time_t startDate, std::time_t endDate,
                         std::time_t createDate)
    : startDate(startDate), endDate(endDate), canceled(false),
      createDate(createDate), roomNumber(roomNumber), id(id), guestId(guestId) {
}

int Reservation::getId() const { return id; }
bool Reservation::isCanceled() const { return canceled; }
void Reservation::cancel() { canceled = true; }
void Reservation::checkIn(std::time_t now) {
  checkedIn = true;
  checkInTime = now;
}
bool Reservation::isCheckedIn() const { return checkedIn; }
int Reservation::getGuestId() const { return guestId; }
void Reservation::addService(const AdditionalService &service) {
  services.push_back(service);
}
double Reservation::getServicesTotal() const {
  double total = 0;
  for (std::size_t i = 0; i < services.size(); i++) {
    total += services[i].getPrice();
  }
  return total;
}

std::time_t Reservation::getStartDate() const { return startDate; }
std::time_t Reservation::getEndDate() const { return endDate; }

void Reservation::displayData() const {
  cout << "- Rezerwacja nr " << id << ", pokój " << roomNumber << ", "
       << formatDate(startDate) << " - " << formatDate(endDate);
  if (canceled) {
    cout << " [anulowana]";
  }
  if (checkedIn) {
    cout << " [zameldowana]";
  }
  cout << endl;
}
