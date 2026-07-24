#pragma once
#include <vector>

#include "../buildings/building.hpp"
#include "../trucks/truck.hpp"
#include "buildings/building_definition.hpp"

namespace industry_game
{
class World
{
public:
    void add_building(BuildingType type, Position position);
    [[nodiscard]] const std::vector<Building>& get_buildings() const
    {
        return buildings_;
    }
    [[nodiscard]] const std::vector<Truck>& get_trucks() const
    {
        return trucks_;
    }
    std::vector<Building>& get_buildings()
    {
        return buildings_;
    }
    std::vector<Truck>& get_trucks()
    {
        return trucks_;
    }

private:
    std::vector<Building> buildings_;
    std::vector<Truck> trucks_;
};
} // namespace industry_game