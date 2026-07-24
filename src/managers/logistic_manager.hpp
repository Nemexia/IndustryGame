#pragma once
#include <vector>

#include "../buildings/building.hpp"
#include "../trucks/truck.hpp"
namespace industry_game
{
class LogisticManager
{
public:
    void update(std::vector<Building>& buildings, std::vector<Truck>& trucks);

private:
    void fill_trucks(std::vector<Building>& buildings, std::vector<Truck>& trucks);
};
} // namespace industry_game
