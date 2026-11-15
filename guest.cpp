#include "guest.h"

Guest::Guest(const std::string &name, const std::string &surname, int id)
    : Person(name, surname, id) {}

void Guest::addFee(double fee) { outstandingFees += fee; }
double Guest::getOutstandingFees() const { return outstandingFees; }
