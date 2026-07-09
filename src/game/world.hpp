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
    void update();
    const std::vector<Building>& get_buildings() const { return buildings_; }
    const std::vector<Truck>& get_trucks() const { return trucks_; }

  private:
    std::vector<Building> buildings_;
    std::vector<Truck> trucks_;
};
} // namespace industry_game