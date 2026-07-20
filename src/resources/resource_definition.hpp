#pragma once
#include "../core/color.hpp"

#include <array>
#include <cstdint>
#include <string_view>

namespace industry_game
{
enum class ResourceType : std::uint8_t
{
    Coal,
    IronOre,
    Steel,
    count,
};
struct ResourceDefinition
{
    std::string_view name;
    Color color;
};

inline constexpr std::array<ResourceDefinition, static_cast<std::size_t>(ResourceType::count)>
    resource_definitions = {{ResourceDefinition{"Coal", Color{0, 0, 0}},
                             ResourceDefinition{"Iron Ore", Color{175, 91, 70}},
                             ResourceDefinition{"Steel", Color{122, 127, 128}}}};

constexpr const ResourceDefinition& get_resource_definition(ResourceType id)
{
    return resource_definitions[static_cast<std::size_t>(id)];
}
} // namespace industry_game