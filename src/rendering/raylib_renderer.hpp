#pragma once
#include "irenderer.hpp"

namespace industry_game
{
class RaylibRenderer : public IRenderer
{
  public:
    void draw_circle(Position position, int radius, Color color,
                     unsigned char alpha) const override;
    void draw_rectangle(Position position, int width, int height, Color color,
                        unsigned char alpha) const override;
};
} // namespace industry_game