#pragma once
#include "../core/id.hpp"
#include "../core/position.hpp"
#include "building_definition.hpp"
#include "core/color.hpp"
#include "resources/resource_definition.hpp"
#include "resources/resource_processor.hpp"

#include <array>
#include <vector>

namespace industry_game
{
class Building
{
  public:
    Building(BuildingType type, Position position, std::vector<TruckID> its_trucks)
        : type_(type)
        , position_(position)
        , resource_processors_(get_building_definition(type).resource_processors)
        , trucks_(its_trucks)
    {
    }
    const Position& get_position() const
    {
        return position_;
    }
    const double& get_size() const
    {
        return get_building_definition(type_).size;
    }
    const Color get_color() const
    {
        return get_resource_definition(
                   get_building_definition(type_).resource_processors[0].storage.resource.id)
            .color;
    }
    const double get_alpha() const
    { // TODO: Implement this
        return 255;
    }

  private:
    Position position_;
    std::vector<ResourceProcessor> resource_processors_;
    std::vector<TruckID> trucks_;
    BuildingType type_;
};
} // namespace industry_game