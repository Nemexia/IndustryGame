#pragma once
#include "resource_definition.hpp"

namespace industry_game
{
class ResourceStorage
{
public:
    ResourceStorage(ResourceType resource, double capacity, double amount = 0.0)
        : stored_amount_(amount),
          capacity_(capacity),
          resource_(resource)
    {
    }
    double add(double amount)
    {
        const double added = std::min(amount, free_space());
        stored_amount_ += added;
        return added;
    }
    double take(double amount)
    {
        const double removed = std::min(stored(), amount);
        stored_amount_ -= removed;
        return removed;
    }
    [[nodiscard]] double stored() const
    {
        return stored_amount_;
    }
    [[nodiscard]] double free_space() const
    {
        return capacity_ - stored_amount_;
    }
    [[nodiscard]] double capacity() const
    {
        return capacity_;
    }
    [[nodiscard]] ResourceType resource() const
    {
        return resource_;
    }
    [[nodiscard]] bool empty() const
    {
        return stored_amount_ == 0.0;
    }
    [[nodiscard]] bool full() const
    {
        return stored_amount_ == capacity_;
    }
    [[nodiscard]] double fill_ratio() const
    {
        return stored_amount_ / capacity_;
    }

private:
    double stored_amount_;
    double capacity_;
    ResourceType resource_;
};
} // namespace industry_game