#pragma once
#include "../resources/resource_processor.hpp"
#include "../trucks/truck_definition.hpp"
#include "resources/resource_definition.hpp"
#include "resources/resource_storage.hpp"

#include <string_view>
#include <vector>

namespace industry_game
{
enum class BuildingType : std::uint8_t
{
    CoalMine,
    IronOreMine,
    SteelMill,
    count,
};
struct BuildingDefinition
{
    std::string_view name;
    double size;
    double efficiency;
    std::vector<ResourceProcessor> resource_processors;
    std::vector<TruckType> trucks_;
};

inline const std::array<BuildingDefinition, static_cast<std::size_t>(BuildingType::count)>
    building_definitions = {
        {BuildingDefinition{"Coal Mine",
                            10,
                            0.5,
                            {ResourceProcessor{ResourceStorage{ResourceType::Coal, 10, 0}, 1}},
                            {TruckType::SmallCoal}},
         BuildingDefinition{"Iron Ore Mine",
                            10,
                            0.5,
                            {ResourceProcessor{ResourceStorage{ResourceType::IronOre, 10, 0}, 1}},
                            {TruckType::SmallIronOre}},
         BuildingDefinition{
             "Steel Mill",
             10,
             0.5,
             {
                 ResourceProcessor{ResourceStorage{ResourceType::Steel, 10, 0}, 1},
                 ResourceProcessor{ResourceStorage{ResourceType::Coal, 10, 0}, -1},
                 ResourceProcessor{ResourceStorage{ResourceType::IronOre, 10, 0}, -1},
             },
             {TruckType::SmallSteel}}}};

constexpr const BuildingDefinition& get_building_definition(BuildingType id)
{
    return building_definitions[static_cast<std::size_t>(id)];
}
} // namespace industry_game