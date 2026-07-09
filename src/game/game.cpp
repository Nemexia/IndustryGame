#include "game.hpp"
namespace industry_game
{
void Game::run()
{
    while (!graphic_rendere_->window_should_close())
    {
        handle_input_events();
        update();
        draw();
    }
    graphic_rendere_->close_window();
}
void Game::draw()
{
    graphic_rendere_->begin_drawing();
    graphic_rendere_->clear_background({0, 0, 0});
    world_renderer_.draw(world_, *graphic_rendere_);
    graphic_rendere_->end_drawing();
}
} // namespace industry_game
