#pragma once
#include <array>
#include <cstdint>
#include <string_view>
#include <utility>

#include "../core/color.hpp"

namespace industry_game
{
enum class ResourceType : std::uint8_t
{
    coal,
    iron_ore,
    steel,
    count,
};
struct ResourceDefinition
{
    std::string_view name;
    Color color;
};

inline constexpr std::array<ResourceDefinition, static_cast<std::size_t>(ResourceType::count)>
    resource_definitions = {
        {ResourceDefinition{.name = "Coal", .color = Color{.r = 0, .g = 0, .b = 0}},
         ResourceDefinition{.name = "Iron Ore", .color = Color{.r = 175, .g = 91, .b = 70}},
         ResourceDefinition{.name = "Steel", .color = Color{.r = 122, .g = 127, .b = 128}}}};
constexpr const ResourceDefinition& get_resource_definition(ResourceType type)
{
    return resource_definitions.at(std::to_underlying(type));
}
} // namespace industry_game