#pragma once
#include "../core/color.hpp"

#include <array>
#include <cstdint>

namespace industry_game
{
enum class ResourceID : std::uint8_t
{
    Coal,
    IronOre,
    Steel,
    count,
};
struct ResourceDefinition
{
    const char* name;
    Color color;
};

constexpr std::array<ResourceDefinition, static_cast<std::size_t>(ResourceID::count)>
    resource_definitions = {{ResourceDefinition{"Coal", Color{255, 255, 255}},
                             ResourceDefinition{"Iron Ore", Color{175, 91, 70}},
                             ResourceDefinition{"Steel", Color{122, 127, 128}}}};

constexpr const ResourceDefinition& get_resource_definition(ResourceID id)
{
    return resource_definitions[static_cast<std::size_t>(id)];
}
} // namespace industry_game