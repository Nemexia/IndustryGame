#pragma once
#include "../rendering/irenderer.hpp"
#include "../rendering/world_renderer.hpp"

namespace industry_game
{
class Game
{
  public:
    Game(const char* name, IRenderer* graphic_render, int width, int height, int fps)
        : world_()
        , world_renderer_()
        , graphic_renderer_(graphic_render) {};
    void run();

  private:
    void handle_input_events();
    void update();
    void draw();
    World world_;
    WorldRenderer world_renderer_;
    IRenderer* graphic_renderer_;
};
} // namespace industry_game