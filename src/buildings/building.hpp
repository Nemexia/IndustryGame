#pragma once
#include <utility>
#include <vector>

#include "../core/color.hpp"
#include "../core/id.hpp"
#include "../core/position.hpp"
#include "../resources/resource_definition.hpp"
#include "../resources/resource_processor.hpp"
#include "building_definition.hpp"

namespace industry_game
{
class Building
{
public:
    Building(BuildingType type, Position position, std::vector<TruckID> its_trucks)
        : type_(type),
          position_(position),
          resource_processors_(get_building_definition(type).resource_processors),
          trucks_(std::move(its_trucks))
    {
    }
    [[nodiscard]] const Position& position() const
    {
        return position_;
    }
    [[nodiscard]] const double& size() const
    {
        return get_building_definition(type_).size;
    }
    [[nodiscard]] Color color() const
    {
        return get_resource_definition(
                   get_building_definition(type_).resource_processors[0].resource_type())
            .color;
    }
    [[nodiscard]] double alpha() const
    {
        return resource_processors_[0].fill_ratio() * 255;
    }
    std::vector<ResourceProcessor>& get_resource_processors()
    {
        return resource_processors_;
    }
    BuildingType get_type() const
    {
        return type_;
    }

private:
    Position position_;
    std::vector<ResourceProcessor> resource_processors_;
    std::vector<TruckID> trucks_;
    BuildingType type_;
};
} // namespace industry_game