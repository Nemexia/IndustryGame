#include "game.hpp"

#include <random>

#include "buildings/building_definition.hpp"
#include "core/position.hpp"

namespace industry_game
{
void Game::run()
{
    while (!graphic_renderer_->window_should_close())
    {
        handle_input_events();
        update();
        draw();
    }
    graphic_renderer_->close_window();
}
void Game::draw()
{
    graphic_renderer_->begin_drawing();
    graphic_renderer_->clear_background({.r = 255, .g = 255, .b = 255});
    world_renderer_.draw(world_, *graphic_renderer_);
    graphic_renderer_->end_drawing();
}
void Game::handle_input_events()
{
    static std::mt19937 generator(std::random_device{}());
    static std::uniform_int_distribution<int> width_dist(0, width_);
    static std::uniform_int_distribution<int> height_dist(0, height_);

    auto random_position = [&]() -> Position
    {
        auto x = static_cast<double>(width_dist(generator));
        auto y = static_cast<double>(height_dist(generator));
        return Position{.x = x, .y = y};
    };

    if (graphic_renderer_->is_key_pressed(Key::one))
    {
        world_.add_building(BuildingType::coal_mine, random_position());
    }
    else if (graphic_renderer_->is_key_pressed(Key::two))
    {
        world_.add_building(BuildingType::iorn_ore_mine, random_position());
    }
    else if (graphic_renderer_->is_key_pressed(Key::three))
    {
        world_.add_building(BuildingType::steel_mill, random_position());
    }
}
void Game::update()
{
    production_manager_.update(world_.get_buildings());
    logistic_manager_.update(world_.get_buildings(), world_.get_trucks());
}
} // namespace industry_game
