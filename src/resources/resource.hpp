#pragma once
#include "resource_definition.hpp"

namespace industry_game
{
struct Resource
{
    const ResourceDefinition& definition;
    double amount;
};
} // namespace industry_game
