#pragma once
#include "additional_service.h"
#include <ctime>

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
  std::time_t checkInTime;

public:
  double countCancellationFee(const Reservation &res, int daysToCancel,
                              double cancellationFeeAmount);
  Reservation(int id, int guestId, int roomNumber, std::time_t startDate,
              std::time_t endDate);

  int getId() const;
  bool isCanceled() const;
  void cancel();
  int getRoomNumber() const;
  bool coversDate(time_t checkStartDate, time_t checkEndDate) const;
  void checkIn();
  bool isCheckedIn();
  int getGuestId();
};
