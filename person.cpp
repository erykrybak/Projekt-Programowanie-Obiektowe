#include "person.h"
#include <iostream>
using namespace std;

Person::Person(const string &name, const string &surname, int id)
    : name(name), surname(surname), id(id) {}

Person::~Person() = default;

int Person::getId() const { return id; }
string Person::getName() const { return name; }
string Person::getSurname() const { return surname; }
void Person::displayData() const {
  cout << "Imię: " << name << "\nNazwisko: " << surname << "\nID: " << id << endl;
}
