#pragma once
#include "../core/id.hpp"
#include "../core/position.hpp"
#include "../resources/resource_storage.hpp"
#include "truck_definition.hpp"

namespace industry_game
{
class Truck
{
  public:
    Truck(TruckType type, Position spawn_position, BuildingID home_base)
        : cargo_({
              get_truck_definition(type).resource,
              get_truck_definition(type).capacity,
              0.0,
          })
        , position_(spawn_position)
        , home_base_(home_base)
        , target(home_base)
        , type_(type) {};

    const Position get_position() const
    {
        return position_;
    }
    const double get_size() const
    {
        return cargo_.capacity();
    }
    const Color get_color() const
    {
        return get_resource_definition(cargo_.resource()).color;
    }
    const double get_alpha() const
    {
        return cargo_.fill_ratio() * 255;
    }

  private:
    ResourceStorage cargo_;
    Position position_;
    BuildingID home_base_;
    BuildingID target;
    TruckType type_;
};
} // namespace industry_game