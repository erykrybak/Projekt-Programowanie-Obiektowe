#pragma once
#include "additional_service.h"
#include "guest.h"
#include "room.h"
#include "bill.h"
#include <ctime>
#include <vector>
#include <memory>

class Reservation {
private:
  int id;
  Guest* guest;
  std::time_t startDate;
  std::time_t endDate;
  Room* room;
  std::vector<AdditionalService*> addedServices;
  std::time_t createDate;
  bool canceled;
  bool checkedIn = false;
  std::time_t checkInTime;
  std::unique_ptr<Bill> bill = nullptr;

public:
  Reservation(int id, Guest* guest, Room* room, std::time_t startDate, std::time_t endDate);
  void addAdditionalService(AdditionalService* additionalService);
  int getId() const;
  double countCancellationFee(int daysToCancel, double cancellationFeeAmount);
  bool isCanceled() const;
  void cancel();
  int getRoomNumber() const;
  bool coversDate(time_t checkStartDate, time_t checkEndDate) const;
  void checkIn();
  bool isCheckedIn();
  int getGuestId();
  void getBill();
};
