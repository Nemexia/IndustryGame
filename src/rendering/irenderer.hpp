#pragma once
#include "../core/color.hpp"
namespace industry_game
{
class IRenderer
{
  public:
    virtual ~IRenderer() = default;
    virtual void draw_circle(int x, int y, int radius, Color color, unsigned char alpha) = 0;
    virtual void draw_rectangle(int x, int y, int width, int height, Color color,
                                unsigned char alpha) = 0;
};
} // namespace industry_game