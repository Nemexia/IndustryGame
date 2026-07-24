#pragma once
#include "resource_definition.hpp"
#include "resource_storage.hpp"

namespace industry_game
{
class ResourceProcessor
{
public:
    ResourceProcessor(ResourceStorage storage, double rate)
        : storage_(storage),
          rate_(rate) {};
    [[nodiscard]] ResourceType resource_type() const
    {
        return storage_.resource_type();
    }
    [[nodiscard]] double rate() const
    {
        return rate_;
    }
    [[nodiscard]] double fill_ratio() const
    {
        return storage_.fill_ratio();
    }
    double process(double factor)
    {
        const auto change = rate_ * factor;
        double changed;
        // TODO: Might be usless with how building works now... rething add and take implementation
        if (change > 0)
        {
            changed = storage_.add(change);
        }
        else
        {
            changed = storage_.take(-change);
        }
        return changed;
    }
    [[nodiscard]] double rate_factor() const
    {
        if (rate_ < 0)
        {
            return storage_.stored() / -rate_;
        }
        return storage_.free_space() / rate_;
    }
    [[nodiscard]] double store_amount() const
    {
        return storage_.stored();
    }
    double take(double amount)
    {
        return storage_.take(amount);
    }

private:
    ResourceStorage storage_;
    double rate_;
};
} // namespace industry_game