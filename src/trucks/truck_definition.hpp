#pragma once
#include "../resources/resource_storage.hpp"

namespace industry_game
{
struct TruckDefinition
{
    const char* name;
    double size;
    double speed;
    ResourceStorage storage;
};
namespace truck
{
constexpr TruckDefinition coal_truck = {"Coal Truck", 1, 1,
                                        ResourceStorage{{resource::coal, 0}, 10}};
constexpr TruckDefinition iron_ore_truck = {"Iron Ore Truck", 1, 1,
                                            ResourceStorage{{resource::iron_ore, 0}, 10}};
constexpr TruckDefinition steel_truck = {"Steel Truck", 1, 1,
                                         ResourceStorage{{resource::steel, 0}, 10}};
} // namespace truck
} // namespace industry_game