#include "bill.h"
#include <ctime>
using namespace std;

Bill::Bill(int billID, const Room &room, double servicesTotal, time_t startDate,
           time_t endDate)
    : billID(billID), creationDate(time(nullptr)), total(0.0) {
  countTotal(room, servicesTotal, startDate, endDate);
}

void Bill::countTotal(const Room &room, double servicesTotal, time_t startDate,
                      time_t endDate) {
  double seconds = difftime(endDate, startDate);
  double seconds_in_a_day = 86400;
  int days = static_cast<int>(seconds / seconds_in_a_day);
  if (days < 1) {
    days = 1;
  }

  double roomRate = room.getRoomRate();
  total = (days * roomRate) + servicesTotal;
}

double Bill::getTotal() const { return total; }
int Bill::getId() const { return billID; }
