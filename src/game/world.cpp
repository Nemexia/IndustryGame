#include "world.hpp"

#include <vector>

#include "buildings/building.hpp"
#include "buildings/building_definition.hpp"
#include "core/id.hpp"
#include "resources/resource_definition.hpp"

namespace industry_game
{
void World::add_building(BuildingType type, Position position)
{
    auto building_id = static_cast<BuildingID>(buildings_.size());
    std::vector<TruckID> trucks_made;
    for (const auto& processor : get_building_definition(type).resource_processors)
    {
        if (processor.rate() < 0)
            continue;
        auto truck_id = static_cast<TruckID>(trucks_.size());
        trucks_made.emplace_back(truck_id);

        TruckType truck_type;
        if (processor.resource_type() == ResourceType::coal)
        {
            truck_type = TruckType::small_coal;
        }
        else if (processor.resource_type() == ResourceType::iron_ore)
        {
            truck_type = TruckType::small_iron_ore;
        }
        else if (processor.resource_type() == ResourceType::steel)
        {
            truck_type = TruckType::small_steel;
        }
        trucks_.emplace_back(truck_type, position, building_id);
    }
    buildings_.emplace_back(type, position, trucks_made);
}
void World::update()
{
    for (auto& building : buildings_)
    {
        building.update();
    }
}
} // namespace industry_game