#pragma once
#include "../core/color.hpp"
#include "../core/position.hpp"

#include <string_view>
namespace industry_game
{

enum class Key
{
    One,
    Two,
    Three,
};
class IRenderer
{
  public:
    virtual ~IRenderer() = default;
    virtual void initialize(std::string_view name, int width, int height, int target_fps) = 0;
    virtual void draw_circle(Position position, int radius, Color color,
                             unsigned char alpha) const = 0;
    virtual void draw_rectangle(Position position, int width, int height, Color color,
                                unsigned char alpha) const = 0;
    virtual bool window_should_close() const = 0;
    virtual void close_window() = 0;
    virtual void begin_drawing() = 0;
    virtual void end_drawing() = 0;
    virtual void clear_background(Color color) = 0;
    virtual bool is_key_pressed(Key key) = 0;
};
} // namespace industry_game