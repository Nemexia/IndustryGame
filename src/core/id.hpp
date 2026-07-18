#pragma once
#include <cstdint>

namespace industry_game
{
using TruckID = std::uint32_t;
using BuildingID = std::uint32_t;
enum class ResourceID : std::uint8_t
{
    Coal,
    IronOre,
    Steel,
    count,
};
} // namespace industry_game