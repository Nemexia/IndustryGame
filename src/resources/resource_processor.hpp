#pragma once
#include "resource_storage.hpp"

namespace industry_game
{
struct ResourceProcessor
{
    ResourceStorage storage;
    double rate;
    void update(double efficiency)
    {
        storage.resource.amount += rate * efficiency;
        if (storage.resource.amount > storage.capacity)
        {
            storage.resource.amount = storage.capacity;
        }
        else if (storage.resource.amount < 0)
        {
            storage.resource.amount = 0;
        }
    }
};
} // namespace industry_game