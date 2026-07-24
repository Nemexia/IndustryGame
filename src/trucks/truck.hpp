#pragma once
#include "../core/id.hpp"
#include "../core/position.hpp"
#include "../resources/resource_storage.hpp"
#include "resources/resource_definition.hpp"
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
          }),
          position_(spawn_position),
          home_base_(home_base),
          target_(home_base),
          type_(type) {};

    [[nodiscard]] Position position() const
    {
        return position_;
    }
    [[nodiscard]] double size() const
    {
        return cargo_.capacity();
    }
    [[nodiscard]] Color color() const
    {
        return get_resource_definition(cargo_.resource_type()).color;
    }
    [[nodiscard]] double alpha() const
    {
        return cargo_.fill_ratio() * 255;
    }
    [[nodiscard]] ResourceType resource_type() const
    {
        return cargo_.resource_type();
    }
    [[nodiscard]] double resource_amount() const
    {
        return cargo_.stored();
    }

private:
    ResourceStorage cargo_;
    Position position_;
    BuildingID home_base_;
    BuildingID target_;
    TruckType type_;
};
} // namespace industry_game