#pragma once

namespace industry_game
{
enum class ResourceType
{
    Mine,
    Factory,
    Truck,
};
struct ResourceDefinition
{
    ResourceType type;
    const char* name;
};
} // namespace industry_game