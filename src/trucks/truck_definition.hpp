#pragma once
#include "../resources/resource_storage.hpp"

namespace industry_game
{
struct TruckDefinition
{
    const char* name;
    double size;
    double speed;
    ResourceStorage storage;
};
} // namespace industry_game