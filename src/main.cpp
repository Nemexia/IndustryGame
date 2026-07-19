#include "game/game.hpp"
#include "rendering/raylib_renderer.hpp"
#include "version.hpp"

#include <string>

int main()
{
    industry_game::RaylibRenderer raylib_graphic_renderer;
    industry_game::Game game{&raylib_graphic_renderer, 800, 450, 60};
    game.run();
}