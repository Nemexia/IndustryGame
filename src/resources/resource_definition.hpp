#pragma once
#include "../core/color.hpp"
namespace industry_game
{
struct ResourceDefinition
{
    const char* name;
    Color color;
};
namespace resource
{
constexpr ResourceDefinition coal = {"Coal", Color{255, 255, 255}};
constexpr ResourceDefinition iron_ore = {"Iron Ore", Color{175, 91, 70}};
constexpr ResourceDefinition steel = {"Steel", Color{122, 127, 128}};
} // namespace resource
} // namespace industry_game