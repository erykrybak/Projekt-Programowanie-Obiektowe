#include "reservation.h"
#include <ctime>
#include <vector>
#include <memory>
using namespace std;

double Reservation::countCancellationFee(int daysToCancel, double cancellationFeeAmount) {
  double cancellationFee = 0;
  time_t timestamp = time(NULL);

  double secondsInDay = 86400.0;
  int dayDifference = static_cast<int>(difftime(timestamp, createDate) / secondsInDay);

  if (dayDifference > daysToCancel) {
    cancellationFee += cancellationFeeAmount;
  }
  return cancellationFee;
}

int Reservation::getRoomNumber() const { 
    return room ? room->getRoomNumber() : -1; 
}

bool Reservation::coversDate(time_t checkStartDate, time_t checkEndDate) const {
  return !canceled && startDate < checkEndDate && checkStartDate < endDate;
}

Reservation::Reservation(int id, Guest* guest, Room* room, time_t startDate, time_t endDate)
    : id(id), guest(guest), room(room), startDate(startDate), endDate(endDate), canceled(false), createDate(time(nullptr)) {}

int Reservation::getId() const { 
    return id;
}
bool Reservation::isCanceled() const { 
    return canceled;
}
void Reservation::cancel() { 
    canceled = true; 
}
void Reservation::checkIn() { 
    checkedIn = true; 
    checkInTime = time(nullptr);
}
bool Reservation::isCheckedIn() { 
    return checkedIn; 
}
int Reservation::getGuestId() { 
    return guest ? guest->getId() : -1; 
}

void Reservation::addAdditionalService(AdditionalService* additionalService) {
    addedServices.push_back(additionalService);
}

void Reservation::getBill() {
    bill = make_unique<Bill>(id, *room, addedServices, startDate, endDate);
}
