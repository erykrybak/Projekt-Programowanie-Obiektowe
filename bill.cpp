#include "bill.h"
#include "reservation.h"
#include <ctime>
using namespace std;

Bill::Bill(int billID, const Room &room, const std::vector<AdditionalService*> &addedServices, time_t startDate, time_t endDate) : billID(billID), creationDate(time(nullptr)), total(0.0) {
    countTotal(room, addedServices, startDate, endDate);
}

void Bill::countTotal(const Room &room, const std::vector<AdditionalService*> &addedServices, time_t startDate, time_t endDate) {
    double seconds = difftime(endDate, startDate);
    double seconds_in_a_day = 86400;
    int days = static_cast<int>(seconds/seconds_in_a_day);
    if (days<1) {
        days = 1;
    }

    double roomRate = room.getRoomRate();
    double additionalServicesCost = 0;
    for (size_t i=0; i < addedServices.size(); i++) {
        additionalServicesCost += addedServices[i]->getPrice();
    }
    total = (days * roomRate) + additionalServicesCost;
}

double Bill::getTotal() const {
    return total;
}
