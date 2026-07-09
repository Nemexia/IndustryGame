#include "game/game.hpp"
#include "rendering/raylib_renderer.hpp"
#include "version.hpp"

#include <string>


int main()
{
    std::string game_name = std::string{"IndustryGame"} + " " + std::string{industry_game::version};
    industry_game::RaylibRenderer raylib_graphic_renderer;
    industry_game::Game game{game_name.c_str(), &raylib_graphic_renderer, 800, 450, 60};
    game.run();
}