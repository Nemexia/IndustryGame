#pragma once
#include <string_view>

#include "../resources/resource_definition.hpp"

namespace industry_game
{
enum class TruckType : std::uint8_t
{
    small_coal,
    small_iron_ore,
    small_steel,
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
    truck_definitions = {{TruckDefinition{.name = "Small Coal Truck",
                                          .speed = 1,
                                          .capacity = 10,
                                          .resource = ResourceType::coal},
                          TruckDefinition{.name = "Small Iron Ore Truck",
                                          .speed = 1,
                                          .capacity = 10,
                                          .resource = ResourceType::iron_ore},
                          TruckDefinition{.name = "Small Steel Truck",
                                          .speed = 1,
                                          .capacity = 10,
                                          .resource = ResourceType::steel}}};

constexpr const TruckDefinition& get_truck_definition(TruckType type)
{
    return truck_definitions.at(std::to_underlying(type));
}
} // namespace industry_game