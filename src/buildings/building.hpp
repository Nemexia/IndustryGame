#pragma once
#include "../core/id.hpp"
#include "../core/position.hpp"
#include "building_definition.hpp"
#include "core/color.hpp"
#include "resources/resource_definition.hpp"
#include "resources/resource_processor.hpp"

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
                   get_building_definition(type_).resource_processors[0].storage.resource())
            .color;
    }
    const double get_alpha() const
    {
        return resource_processors_[0].storage.fill_ratio() * 255;
    }
    void update()
    {
        // TODO: FIX THIS
        double factor = get_building_definition(type_).conversion_speed;
        const double efficiency = get_building_definition(type_).efficiency;
        for (auto& processor : resource_processors_)
        {
            auto rate_factor = processor.rate_factor();
            if (processor.rate > 0)
            {
                rate_factor *= efficiency;
            }
            factor = std::min(factor, rate_factor);
        }
        for (auto& processor : resource_processors_)
        {
            processor.process(factor);
        }
    }

  private:
    Position position_;
    std::vector<ResourceProcessor> resource_processors_;
    std::vector<TruckID> trucks_;
    BuildingType type_;
};
} // namespace industry_game