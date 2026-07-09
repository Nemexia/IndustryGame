#pragma once
#include "../resources/resource_processor.hpp"
#include "../trucks/truck_definition.hpp"

#include <vector>

namespace industry_game
{
struct BuildingDefinition
{
    const char* name;
    double size;
    double efficiency;
    std::vector<ResourceProcessor> resource_processors;
    std::vector<const TruckDefinition*> truck_definitions;
};

namespace building
{
const BuildingDefinition coal_mine = {
    "Coal Mine",
    1,
    0.5,
    {ResourceProcessor{ResourceStorage{Resource{resource::coal, 0}, 10}, 1}},
    {&truck::coal_truck}};
const BuildingDefinition iron_ore_mine = {
    "Iron Ore Mine",
    1,
    0.5,
    {ResourceProcessor{ResourceStorage{Resource{resource::iron_ore, 0}, 10}, 1}},
    {&truck::iron_ore_truck}};
const BuildingDefinition steel_mine = {
    "Steel Mine",
    1,
    0.5,
    {ResourceProcessor{ResourceStorage{Resource{resource::steel, 0}, 10}, 1}},
    {&truck::steel_truck}};
} // namespace building
} // namespace industry_game