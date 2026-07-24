#include "logistic_manager.hpp"
namespace industry_game
{
void LogisticManager::update(std::vector<Building>& buildings, std::vector<Truck>& trucks)
{
    fill_trucks(buildings, trucks);
}
void LogisticManager::fill_trucks(std::vector<Building>& buildings, std::vector<Truck>& trucks)
{
    for (auto& building : buildings)
    {
        for (auto& processor : building.get_resource_processors())
        {
            {
                if (processor.rate() > 0)
                {
                    auto amount_to_transfer = processor.store_amount();
                    auto resource_type = processor.resource_type();
                    for (auto& truck_id : building.get_trucks())
                    {
                        auto& truck = trucks.at(truck_id);
                        if (truck.resource_type() != resource_type)
                        {
                            continue;
                        }
                        if (buildings.at(truck.home_base()).position() != truck.position())
                        {
                            continue;
                        }
                        if (truck.is_full())
                        {
                            continue;
                        }
                        auto amount_transfered = truck.fill(amount_to_transfer);
                        processor.take(amount_transfered);
                    }
                }
            }
        }
    }
}
} // namespace industry_game
