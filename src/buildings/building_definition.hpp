#pragma once
#include "../resources/resource_processor.hpp"
#include "../trucks/truck_definition.hpp"
#include "resources/resource.hpp"
#include "resources/resource_definition.hpp"
#include "resources/resource_storage.hpp"

#include <vector>

namespace industry_game
{
enum class BuildingType : std::uint8_t
{
    CoalMine,
    IronOreMine,
    SteelMine,
    count,
};
struct BuildingDefinition
{
    const char* name;
    double size;
    double efficiency;
    std::vector<ResourceProcessor> resource_processors;
    std::vector<TruckType> truck_types;
};

const std::array<BuildingDefinition, static_cast<std::size_t>(BuildingType::count)>
    building_definitions = {
        {BuildingDefinition{
             "Coal Mine",
             1,
             0.5,
             {ResourceProcessor{ResourceStorage{Resource{ResourceID::Coal, 0}, 10}, 1}},
             {TruckType::SmallCoal}},
         BuildingDefinition{
             "Iron Ore Mine",
             1,
             0.5,
             {ResourceProcessor{ResourceStorage{Resource{ResourceID::IronOre, 0}, 10}, 1}},
             {TruckType::SmallIronOre}},
         BuildingDefinition{
             "Steel Mine",
             1,
             0.5,
             {
                 ResourceProcessor{ResourceStorage{Resource{ResourceID::Steel, 0}, 10}, 1},
                 ResourceProcessor{ResourceStorage{Resource{ResourceID::Coal, 0}, 10}, -1},
                 ResourceProcessor{ResourceStorage{Resource{ResourceID::IronOre, 0}, 10}, -1},
             },
             {TruckType::SmallSteel}}}};

constexpr const BuildingDefinition& get_building_definition(BuildingType id)
{
    return building_definitions[static_cast<std::size_t>(id)];
}
} // namespace industry_game