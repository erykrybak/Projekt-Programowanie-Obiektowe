#include "additional_service.h"
#include <string>
using namespace std;

AdditionalService::AdditionalService(string name, double price) : name(name), price(price) {}

double AdditionalService::getPrice() const {
    return price;
}

string AdditionalService::getName() const {
    return name;
}
