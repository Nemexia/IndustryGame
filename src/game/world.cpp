#include "world.hpp"

#include "buildings/building.hpp"
#include "buildings/building_definition.hpp"
#include "core/id.hpp"

#include <vector>

namespace industry_game
{
void World::add_building(BuildingType type, Position position)
{
    BuildingID building_id = static_cast<BuildingID>(buildings_.size());
    std::vector<TruckID> trucks_made;
    for (auto& processor : get_building_definition(type).resource_processors)
    {
        TruckID truck_id = static_cast<TruckID>(trucks_.size());
        trucks_made.emplace_back(truck_id);

        TruckType truck_type;
        if (processor.storage.resource.id == ResourceID::Coal)
        {
            truck_type = TruckType::SmallCoal;
        }
        else if (processor.storage.resource.id == ResourceID::IronOre)
        {
            truck_type = TruckType::SmallIronOre;
        }
        else if (processor.storage.resource.id == ResourceID::Steel)
        {
            truck_type = TruckType::SmallSteel;
        }
        trucks_.emplace_back(truck_type, position, building_id);
    }
    buildings_.emplace_back(type, position, trucks_made);
}
void World::update()
{
    // TODO: Implement this
}
} // namespace industry_game