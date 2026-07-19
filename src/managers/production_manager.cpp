#include "production_manager.hpp"
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
        for (auto& processor : building.get_resource_processors())
        {
            auto const delta =
                processor.rate * get_building_definition(building.get_type()).efficiency;
            if (delta > 0)
            {
                if (processor.storage.resource.amount + delta > processor.storage.capacity)
                {
                    return;
                }
            }
            else
            {
                if (processor.storage.resource.amount + delta < 0)
                {
                    return;
                }
            }
        }
        for (auto& processor : building.get_resource_processors())
        {
            processor.update(get_building_definition(building.get_type()).efficiency);
        }
    }
}
} // namespace industry_game

void industry_game::ProductionManager::fill_trucks(std::vector<Building>& buildings,
                                                   std::vector<Truck>& trucks)
{
}
