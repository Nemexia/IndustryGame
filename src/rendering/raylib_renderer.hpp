#pragma once
#include "irenderer.hpp"

#include <raylib.h>

namespace industry_game
{
class RaylibRenderer : public IRenderer
{
  public:
    void initialize(const char* name, int width, int height, int target_fps) override;
    void draw_circle(Position position, int radius, Color color,
                     unsigned char alpha) const override;
    void draw_rectangle(Position position, int width, int height, Color color,
                        unsigned char alpha) const override;
    bool window_should_close() const override;
    void close_window() override;
    void begin_drawing() override;
    void end_drawing() override;
    void clear_background(Color color) override;
    bool is_key_released(Key key) override;
};
} // namespace industry_game