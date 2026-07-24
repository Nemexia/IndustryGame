#pragma once
#include <vector>

#include "../buildings/building.hpp"
namespace industry_game
{
class ProductionManager
{
public:
    void update(std::vector<Building>& buildings);

private:
    void produce_resources(std::vector<Building>& buildings);
};
} // namespace industry_game
