#pragma once
#include <string>

class Person {
private:
  std::string surname;
  std::string name;
  int id;

public:
  Person(std::string name, std::string surname, int id);
  int getId() const;
  std::string getName() const;
  std::string getSurname() const;
};
