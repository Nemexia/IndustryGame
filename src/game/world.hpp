#pragma once
#include "../buildings/building.hpp"
#include "../trucks/truck.hpp"

#include <vector>
namespace industry_game
{
class World
{
  public:
    void add_truck(Truck truck);
    void add_building(Building building);

  private:
    std::vector<Building> buildings_;
    std::vector<Truck> trucks_;
};
} // namespace industry_game