#pragma once
#include "resources/resource_definition.hpp"

#include <string_view>

namespace industry_game
{
enum class TruckType : std::uint8_t
{
    SmallCoal,
    SmallIronOre,
    SmallSteel,
    count,
};

struct TruckDefinition
{
    std::string_view name;
    double speed;
    double capacity;
    ResourceType resource;
};

inline constexpr std::array<TruckDefinition, static_cast<std::size_t>(TruckType::count)>
    truck_definitions = {{TruckDefinition{"Small Coal Truck", 1, 10, ResourceType::Coal},
                          TruckDefinition{"Small Iron Ore Truck", 1, 10, ResourceType::IronOre},
                          TruckDefinition{"Small Steel Truck", 1, 10, ResourceType::Steel}}};

constexpr const TruckDefinition& get_truck_definition(TruckType id)
{
    return truck_definitions[static_cast<std::size_t>(id)];
}
} // namespace industry_game