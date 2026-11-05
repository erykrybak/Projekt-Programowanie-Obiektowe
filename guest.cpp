#include "guest.h"

Guest::Guest(std::string name, std::string surname, int id)
    : Person(name, surname, id) {}

int Guest::getId() const { return id; }
