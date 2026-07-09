#pragma once
#include "../core/id.hpp"
#include "../core/position.hpp"
#include "truck_definition.hpp"

namespace industry_game
{
class Truck
{
  public:
    Truck(TruckType type, Position spawn_position, BuildingID home_base)
        : cargo_(Resource{get_truck_definition(type).resource, 0.0},
                 get_truck_definition(type).capacity)
        , position_(spawn_position)
        , home_base_(home_base)
        , target(home_base)
        , type_(type) {};

  private:
    ResourceStorage cargo_;
    Position position_;
    BuildingID home_base_;
    BuildingID target;
    TruckType type_;
};
} // namespace industry_game