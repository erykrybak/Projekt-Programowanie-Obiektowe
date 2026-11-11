#include "person.h"

Person::Person(std::string name, std::string surname, int id)
      : name(name), surname(surname), id(id) {}

int Person::getId() const{ return id; }
std::string Person::getName() const { return name; };
std::string Person::getSurname() const{ return surname; };

