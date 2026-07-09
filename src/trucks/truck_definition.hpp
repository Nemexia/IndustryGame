#pragma once
#include "../resources/resource_storage.hpp"

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
    const char* name;
    double size;
    double speed;
    double capacity;
    ResourceID resource;
};

constexpr std::array<TruckDefinition, static_cast<std::size_t>(TruckType::count)>
    truck_definitions = {{TruckDefinition{"Small Coal Truck", 1, 1, 10, ResourceID::Coal},
                          TruckDefinition{"Small Iron Ore Truck", 1, 1, 10, ResourceID::IronOre},
                          TruckDefinition{"Small Steel Truck", 1, 1, 10, ResourceID::Steel}}};

constexpr const TruckDefinition& get_truck_definition(TruckType id)
{
    return truck_definitions[static_cast<std::size_t>(id)];
}
} // namespace industry_game