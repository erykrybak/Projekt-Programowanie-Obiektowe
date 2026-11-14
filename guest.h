#pragma once
#include "person.h"
#include <string>

class Guest : public Person {
public:
  Guest(const std::string& name, const std::string& surname, int id);
};
