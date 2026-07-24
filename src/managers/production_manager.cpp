#include "production_manager.hpp"

#include "../buildings/building_definition.hpp"

namespace industry_game
{
void ProductionManager::update(std::vector<Building>& buildings, std::vector<Truck>& trucks)
{
    produce_resources(buildings);
    fill_trucks(buildings, trucks);
}
void ProductionManager::produce_resources(std::vector<Building>& buildings)
{
    for (auto& building : buildings)
    {
        double factor = get_building_definition(building.get_type()).conversion_speed;
        const double efficiency = get_building_definition(building.get_type()).efficiency;
        for (auto& processor : building.get_resource_processors())
        {
            auto rate_factor = processor.rate_factor();
            if (processor.rate() > 0)
            {
                rate_factor *= efficiency;
            }
            factor = std::min(factor, rate_factor);
        }
        for (auto& processor : building.get_resource_processors())
        {
            processor.process(factor);
        }
    }
}

void ProductionManager::fill_trucks(std::vector<Building>& buildings, std::vector<Truck>& trucks)
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
                        auto & truck = trucks.at(truck_id);
                        if (truck.resource_type() != resource_type)
                        {
                            continue;
                        }
                        if (buildings.at(truck.home_base()).position() != truck.position())
                        {
                            continue;
                        }
                        if(truck.is_full())
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
