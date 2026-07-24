#include "world_renderer.hpp"

#include "core/position.hpp"

namespace industry_game
{
void WorldRenderer::draw(const World& world, IRenderer& renderer) const
{
    for (const auto& building : world.get_buildings())
    {
        draw(building, renderer);
    }
    for (const auto& truck : world.get_trucks())
    {
        draw(truck, renderer);
    }
}
void WorldRenderer::draw(const Building& building, IRenderer& renderer) const
{
    const Position position{.x = building.position().x - (building.size() / 2),
                            .y = building.position().y - (building.size() / 2)};
    renderer.draw_rectangle(position,
                            building.size(),
                            building.size(),
                            building.color(),
                            building.alpha());
}
void WorldRenderer::draw(const Truck& truck, IRenderer& renderer) const
{
    renderer.draw_circle(
        truck.position(), truck.size(), truck.color(), truck.alpha());
}
} // namespace industry_game