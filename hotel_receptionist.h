#include "person.h"
#include "reservation.h"

class HotelReceptionist : private Person {
private:
  int workerID;

public:
  bool guestCheckIn(int guestId, int reservationId);
  bool guestCheckOut(int reservationId);
};
