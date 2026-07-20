#pragma once
#include "resource_definition.hpp"

namespace industry_game
{
class ResourceStorage
{
    public:
    ResourceStorage(ResourceType resource, double capacity, double amount=0.0): amount_(amount), capacity_(capacity), resource_(resource) {}
    void fill(double amount); // TODO: Implement this
    private:
    double amount_;
    double capacity_;
    ResourceType resource_;
};
} // namespace industry_game