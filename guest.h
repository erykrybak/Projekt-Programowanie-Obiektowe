#include "person.h"
#include "reservation.h"
#include "additional_service.h"
#include <vector>
#include <ctime>

class Guest: private Person{
    private:
        std::vector<Reservation> reservations;
    public:
        Reservation makeReservation(std::time_t date, std::vector<AdditionalService> services);
        void cancelReservation(Reservation reservation);
};