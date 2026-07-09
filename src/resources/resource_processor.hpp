#pragma once
#include "resource_storage.hpp"

namespace industry_game
{
struct ResourceProcessor
{
    ResourceStorage storage;
    double rate;
};
} // namespace industry_game