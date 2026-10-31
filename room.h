#pragma once
class Room {
private:
  int roomNumber;
  double roomRate;

public:
  int getRoomNumber() const;
  Room(int roomNumber, double roomRate);
};
