#include "reservation.h"
#include <ctime>
using namespace std;

double Reservation::countCancellationFee(const Reservation &res,
                                         int daysToCancel,
                                         double cancellationFeeAmount) {
  double cancellationFee = 0;
  time_t timestamp = time(NULL);

  double secondsInDay = 86400.0;
  int dayDifference = difftime(timestamp, res.createDate) / secondsInDay;

  if (dayDifference > daysToCancel) {
    cancellationFee += cancellationFeeAmount;
  }
  return cancellationFee;
}

int Reservation::getRoomNumber() const { return roomNumber; }

bool Reservation::coversDate(time_t checkStartDate, time_t checkEndDate) const {
  return !canceled && startDate < checkEndDate && checkStartDate < endDate;
}

Reservation::Reservation(int id, int guestId, int roomNumber,
                         std::time_t startDate, std::time_t endDate)
    : id(id), guestId(guestId), roomNumber(roomNumber), startDate(startDate),
      endDate(endDate), canceled(false), createDate(std::time(nullptr)) {}

int Reservation::getId() const { return id; }
bool Reservation::isCanceled() const { return canceled; }
void Reservation::cancel() { canceled = true; }
void Reservation::checkIn() { 
    checkedIn = true; 
    checkInTime = std::time(nullptr);
}
bool Reservation::isCheckedIn() { return checkedIn; }
int Reservation::getGuestId() { return guestId; }

