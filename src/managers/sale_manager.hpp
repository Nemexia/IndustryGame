#pragma once
#include "../core/id.hpp"
#include "buildings/building.hpp"
#include "trucks/truck.hpp"

#include <vector>

namespace industry_game
{
struct SellOrder
{
    TruckID truck_id;
    ResourceID resource;
    int amount;
};
class SaleManager
{
  public:
    void update(std::vector<Building>& buidlings, std::vector<Truck>& trucks);

  private:
    std::vector<SellOrder> orders_;
};
} // namespace industry_game