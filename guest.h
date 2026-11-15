#pragma once
#include "person.h"
#include <string>

class Guest : public Person {
private:
  double outstandingFees = 0;

public:
  Guest(const std::string &name, const std::string &surname, int id);
  void addFee(double fee);
  double getOutstandingFees() const;
};
