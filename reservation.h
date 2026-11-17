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
  std::time_t checkInTime{0};
  std::vector<AdditionalService> services;

public:
  double countCancellationFee(int daysToCancel, double cancellationFeeAmount,
                              std::time_t now) const;
  Reservation(int id, int guestId, int roomNumber, std::time_t startDate,
              std::time_t endDate, std::time_t createDate);

  int getId() const;
  bool isCanceled() const;
  void cancel();
  int getRoomNumber() const;
  bool coversDate(time_t checkStartDate, time_t checkEndDate) const;
  void checkIn(std::time_t now);
  bool isCheckedIn() const;
  int getGuestId() const;
  void addService(const AdditionalService &service);
  double getServicesTotal() const;
  std::time_t getStartDate() const;
  std::time_t getEndDate() const;
  void displayData() const;
};
