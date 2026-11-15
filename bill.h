#pragma once
#include "room.h"
#include "additional_service.h"
#include <ctime>
#include <vector>

class Bill {
private:
  int billID;
  std::time_t creationDate;
  double total;

public:
  Bill(int billID, const Room &room, const std::vector<AdditionalService*> &addedServices, time_t startDate, time_t endDate);
  void countTotal(const Room &room, const std::vector<AdditionalService*> &addedServices, time_t startDate, time_t endDate);
  double getTotal() const;
};
