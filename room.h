#pragma once
class Room {
private:
  int roomNumber;
  double roomRate;

public:
  Room(int roomNumber, double roomRate);
  int getRoomNumber() const;
  double getRoomRate() const;
};
