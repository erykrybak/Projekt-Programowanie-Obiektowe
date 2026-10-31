#include "room.h"

int Room::getRoomNumber() const { return roomNumber; }
Room::Room(int roomNumber, double roomRate)
    : roomNumber(roomNumber), roomRate(roomRate) {}
