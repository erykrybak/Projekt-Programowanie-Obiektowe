#include "room.h"
#include "reservation.h"
#include "guest.h"
#include <time>
#include <vector>

class HotelSystem{
    private:
        std::vector<Room> roomList;
        std::vector<Reservation> reservationList;
        std::vector<Guest> guestList;
    public:
        std::vector<Room> checkAvailability(std::time_t date);
};