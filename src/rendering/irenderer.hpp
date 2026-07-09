#pragma once
#include "../core/color.hpp"
#include "../core/position.hpp"
namespace industry_game
{
class IRenderer
{
  public:
    virtual ~IRenderer() = default;
    virtual void draw_circle(Position position, int radius, Color color,
                             unsigned char alpha) const = 0;
    virtual void draw_rectangle(Position position, int width, int height, Color color,
                                unsigned char alpha) const = 0;
};
} // namespace industry_game