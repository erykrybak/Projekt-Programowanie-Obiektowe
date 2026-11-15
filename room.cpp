#include "room.h"

Room::Room(int roomNumber, double roomRate)
    : roomNumber(roomNumber), roomRate(roomRate) {}
int Room::getRoomNumber() const { 
    return roomNumber; 
}
double Room::getRoomRate() const {
    return roomRate;
}
