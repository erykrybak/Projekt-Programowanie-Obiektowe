#pragma once
#include "additional_service.h"
#include <ctime>
#include <vector>

class Reservation {
private:
  std::time_t startDate;
  std::time_t endDate;
  bool canceled;
  std::time_t createDate;
  int roomNumber;
  int id;
  int guestId;
  bool checkedIn = false;
  std::time_t checkInTime {0};
  std::vector<AdditionalService> services;

public:
  double countCancellationFee(int daysToCancel,
                              double cancellationFeeAmount)const;
  Reservation(int id, int guestId, int roomNumber, std::time_t startDate,
              std::time_t endDate);

  int getId() const;
  bool isCanceled() const;
  void cancel();
  int getRoomNumber() const;
  bool coversDate(time_t checkStartDate, time_t checkEndDate) const;
  void checkIn();
  bool isCheckedIn();
  int getGuestId() const;
  void addService(const AdditionalService &service);
  double getServicesTotal();
  std::time_t getStartDate();
  std::time_t getEndDate();
};
