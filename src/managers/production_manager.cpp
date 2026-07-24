#include "production_manager.hpp"

#include "buildings/building_definition.hpp"

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
        double factor =
            get_building_definition(building.get_type()).conversion_speed; // TODOES: make method
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
} // namespace industry_game

void industry_game::ProductionManager::fill_trucks(std::vector<Building>& buildings,
                                                   std::vector<Truck>& trucks)
{
}
