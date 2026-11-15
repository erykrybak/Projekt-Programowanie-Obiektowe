#include "additional_service.h"

AdditionalService::AdditionalService(std::string name, double price)
    : name(name), price(price) {}
  std::string AdditionalService::getName(){
      return name;
  }
double AdditionalService::getPrice(){
    return price;
}

