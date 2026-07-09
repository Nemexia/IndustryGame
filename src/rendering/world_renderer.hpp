#pragma once
#include "../game/world.hpp"
#include "irenderer.hpp"

namespace industry_game
{
class WorldRenderer
{
  public:
    void draw(const World& world, IRenderer& renderer) const;

  private:
    void draw(const Truck&, IRenderer& renderer) const;
    void draw(const Building&, IRenderer& renderer) const;
};
} // namespace industry_game