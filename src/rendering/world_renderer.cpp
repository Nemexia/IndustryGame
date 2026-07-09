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
    const Position position{building.get_position().x - building.get_size() / 2,
                            building.get_position().y - building.get_size() / 2};
    renderer.draw_rectangle(position, building.get_size(), building.get_size(),
                            building.get_color(), building.get_alpha());
}
void WorldRenderer::draw(const Truck& truck, IRenderer& renderer) const
{
    renderer.draw_circle(truck.get_position(), truck.get_size(), truck.get_color(),
                         truck.get_alpha());
}
} // namespace industry_game