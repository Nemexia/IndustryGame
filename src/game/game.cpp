#include "game.hpp"

#include "raylib.h"

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
    graphic_renderer_->clear_background({0, 0, 0});
    world_renderer_.draw(world_, *graphic_renderer_);
    graphic_renderer_->end_drawing();
}
void Game::handle_input_events()
{
    if (graphic_renderer_->is_key_released(Key::One))
    {
        // TODO: Implement this
    }
    else if (graphic_renderer_->is_key_released(Key::Two))
    {
    }
    else if (graphic_renderer_->is_key_released(Key::Three))
    {
    }
}
} // namespace industry_game
