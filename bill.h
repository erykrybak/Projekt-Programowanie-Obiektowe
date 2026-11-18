#pragma once
#include "additional_service.h"
#include "room.h"
#include <ctime>
#include <vector>

class Bill {
private:
  int billID;
  std::time_t creationDate;
  double total;

public:
  Bill(int billID, const Room &room, double servicesTotal, time_t startDate,
       time_t endDate, time_t creationDate);
  void countTotal(const Room &room, double servicesTotal, time_t startDate,
                  time_t endDate); // wyznacza kwotę za pobyt uwzględniającą
                                   // usługi dodatkowe
  double getTotal() const;
  int getId() const;
};
