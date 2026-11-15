#pragma once
#include <string>

class AdditionalService {
private:
  std::string name;
  double price;
public:
  AdditionalService(std::string name, double price);
  double getPrice() const;
  std::string getName() const;
};
