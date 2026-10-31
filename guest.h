#pragma once
#include "person.h"
#include <string>

class Guest : public Person {
public:
  Guest(std::string name, std::string surname, int id);
};
