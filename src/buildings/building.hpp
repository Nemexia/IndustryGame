#pragma once
#include "../core/position.hpp"
#include "building_definition.hpp"

#include <vector>

namespace industry_game
{
class Truck;
class Building
{
  public:
    Building(const BuildingDefinition& building_definition, Position position);

  private:
    const BuildingDefinition& building_definiton_;
    Position position_;
    std::vector<ResourceProcessor> resource_processors_;
    std::vector<Truck> trucks_;
};
} // namespace industry_game