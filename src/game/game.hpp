#pragma once
#include <string>

#include "../managers/logistic_manager.hpp"
#include "../managers/production_manager.hpp"
#include "../rendering/irenderer.hpp"
#include "../rendering/world_renderer.hpp"
#include "../version.hpp"

namespace industry_game
{
inline constexpr std::string_view game_name = "IndustryGame";
class Game
{
public:
    Game(IRenderer* graphic_render, int width, int height, int fps)
        : world_(),
          name_(std::string(game_name) + " " + std::string(version)),
          graphic_renderer_(graphic_render),
          width_(width),
          height_(height),
          fps_(fps),
          world_renderer_()
    {
        graphic_renderer_->initialize(name_, width, height, fps);
    };
    void run();

private:
    void handle_input_events();
    void update();
    void draw();
    World world_;
    std::string name_;
    IRenderer* graphic_renderer_;
    int width_;
    int height_;
    int fps_;
    WorldRenderer world_renderer_;
    ProductionManager production_manager_;
    LogisticManager logistic_manager_;
};
} // namespace industry_game