#pragma once
#include "resource_storage.hpp"

namespace industry_game
{
struct ResourceProcessor
{
    // TODO: MAKE CLASS
    ResourceStorage storage;
    double rate;
    double process(double factor)
    {
        auto const change = rate * factor;
        double changed;
        // TODO: Might be usless with how building works now... rething add and take implementation
        if (change > 0)
        {
            changed = storage.add(change);
        }
        else
        {
            changed = storage.take(-change);
        }
        return changed;
    }
    double rate_factor() const
    {
        if (rate < 0)
        {
            return storage.stored() / -rate;
        }
        else
        {
            return storage.free_space() / rate;
        }
    }
};
} // namespace industry_game