#pragma once
#include "../core/position.hpp"
#include "truck_definition.hpp"

namespace industry_game
{
class Truck
{
  public:
    Truck(TruckType type, Position position)
        : cargo_(Resource{get_truck_definition(type).resource, 0.0},
                 get_truck_definition(type).capacity)
        , position_(position)
        , home_base_(position)
        , target(position)
        , type_(type) {};

  private:
    ResourceStorage cargo_;
    Position position_;
    Position home_base_;
    Position target;
    TruckType type_;
};
} // namespace industry_game