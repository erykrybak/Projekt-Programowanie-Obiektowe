#include "reservation.h"
#include <ctime>
using namespace std;

double countCancellationFee(const Reservation& res, int daysToCancel, double cancellationFeeAmount){
    double cancellationFee = 0;
    time_t timestamp = time(NULL);

    double secondsInDay = 86400.0;
    int dayDifference = difftime(timestamp, res.createDate)/secondsInDay;

    if (dayDifference > daysToCancel) {
	cancellationFee += cancellationFeeAmount;
    }
    return cancellationFee;
}

