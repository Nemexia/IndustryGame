#pragma once
#include "../buildings/building.hpp"
#include "../trucks/truck.hpp"

#include <vector>
namespace industry_game
{
class ProductionManager
{
  public:
    void update(std::vector<Building>& buildings, std::vector<Truck>& trucks);

  private:
    void produce_resources(std::vector<Building>& buildings);
};
} // namespace industry_game
