#include <ctime>
#include "additional_service.h"

class Reservation{
    private:
        std::time_t startDate;
        std::time_t endDate;
        bool canceled;
        std::time_t createDate;
    public:
        double countCancellationFee();
}