#pragma once
#include "../buildings/building.hpp"
#include "../trucks/truck.hpp"
#include "buildings/building_definition.hpp"

#include <vector>
namespace industry_game
{
class World
{
  public:
    void add_building(BuildingType type, Position position);

  private:
    std::vector<Building> buildings_;
    std::vector<Truck> trucks_;
};
} // namespace industry_game