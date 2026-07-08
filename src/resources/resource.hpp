#pragma once
#include "resource_definition.hpp"

namespace industry_game
{
struct Resource
{
    ResourceDefinition& definition;
    int amount;
};
} // namespace industry_game
