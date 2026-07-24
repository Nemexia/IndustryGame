#pragma once
#include <string_view>
#include <utility>
#include <vector>

#include "../resources/resource_definition.hpp"
#include "../resources/resource_processor.hpp"
#include "../resources/resource_storage.hpp"
#include "../trucks/truck_definition.hpp"

namespace industry_game
{
enum class BuildingType : std::uint8_t
{
    coal_mine,
    iorn_ore_mine,
    steel_mill,
    count,
};
struct BuildingDefinition
{
    std::string_view name;
    double size;
    double conversion_speed;
    double efficiency;
    std::vector<ResourceProcessor> resource_processors;
    std::vector<TruckType> trucks;
};

inline const std::array<BuildingDefinition, static_cast<std::size_t>(BuildingType::count)>
    building_definitions = {
        {BuildingDefinition{.name = "Coal Mine",
                            .size = 10,
                            .conversion_speed = 1,
                            .efficiency = 0.5,
                            .resource_processors = {ResourceProcessor{
                                ResourceStorage{ResourceType::coal, 10, 0}, 1}},
                            .trucks = {TruckType::small_coal}},
         BuildingDefinition{.name = "Iron Ore Mine",
                            .size = 10,
                            .conversion_speed = 1,
                            .efficiency = 0.5,
                            .resource_processors = {ResourceProcessor{
                                ResourceStorage{ResourceType::iron_ore, 10, 0}, 1}},
                            .trucks = {TruckType::small_iron_ore}},
         BuildingDefinition{
             .name = "Steel Mill",
             .size = 10,
             .conversion_speed = 1,
             .efficiency = 0.5,
             .resource_processors =
                 {
                     ResourceProcessor{ResourceStorage{ResourceType::steel, 10, 0}, 1},
                     ResourceProcessor{ResourceStorage{ResourceType::coal, 10, 0}, -1},
                     ResourceProcessor{ResourceStorage{ResourceType::iron_ore, 10, 0}, -1},
                 },
             .trucks = {TruckType::small_steel}}}};

constexpr const BuildingDefinition& get_building_definition(BuildingType type)
{
    return building_definitions.at(std::to_underlying(type));
}
} // namespace industry_game