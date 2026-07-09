#pragma once
#include "../buildings/building.hpp"

#include <vector>
namespace industry_game
{
class World
{
  public:
  private:
    std::vector<Building> buildings_;
    std::vector<Truck> trucks_;
};
} // namespace industry_game