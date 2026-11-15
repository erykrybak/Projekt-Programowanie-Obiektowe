#include "reservation.h"
#include <ctime>
using namespace std;

double Reservation::countCancellationFee(int daysToCancel,
                                         double cancellationFeeAmount) const {
    double daysLeft = difftime(startDate, time(nullptr)) / 86400.0;
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
int Reservation::getGuestId() const { return guestId; }
  void Reservation::addService(const AdditionalService &service){
      services.push_back(service);
  }
  double Reservation::getServicesTotal(){
      double total = 0;
      for(std::size_t i =0;i< services.size();i++){
        total += services[i].getPrice();
      }
      return total;
  }

  std::time_t Reservation::getStartDate(){return startDate;}
  std::time_t Reservation::getEndDate(){return endDate;}

