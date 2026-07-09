#pragma once
#include "../game/world.hpp"
#include "irenderer.hpp"


namespace industry_game
{
class WorldRenderer
{
  public:
    void draw(const World& world, IRenderer& renderer) const;
};
} // namespace industry_game