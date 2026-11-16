#pragma once
#include <string>

class Person {
private:
  std::string name;
  std::string surname;
  int id;

public:
  Person(const std::string &name, const std::string &surname, int id);
  virtual ~Person();
  int getId() const;
  std::string getName() const;
  std::string getSurname() const;
  virtual void displayData() const = 0;
};
