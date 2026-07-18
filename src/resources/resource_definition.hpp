#pragma once
#include "../core/color.hpp"

#include <array>
#include <cstdint>

namespace industry_game
{
struct ResourceDefinition
{
    const char* name;
    Color color;
};

inline constexpr std::array<ResourceDefinition, static_cast<std::size_t>(ResourceID::count)>
    resource_definitions = {{ResourceDefinition{"Coal", Color{0, 0, 0}},
                             ResourceDefinition{"Iron Ore", Color{175, 91, 70}},
                             ResourceDefinition{"Steel", Color{122, 127, 128}}}};

constexpr const ResourceDefinition& get_resource_definition(ResourceID id)
{
    return resource_definitions[static_cast<std::size_t>(id)];
}
} // namespace industry_game