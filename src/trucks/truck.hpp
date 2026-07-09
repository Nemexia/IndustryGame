#pragma once
#include "../core/position.hpp"
#include "truck_definition.hpp"

namespace industry_game
{
class Building;
class Truck
{
  public:
    Truck(const TruckDefinition& truck_definition, Building& home_building);

  private:
    const TruckDefinition& truck_definition_;
    Position position_;
    Building* target_building_;
    Building& home_building_;
};
} // namespace industry_game