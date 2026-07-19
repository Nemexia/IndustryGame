#include "raylib_renderer.hpp"

#include "raylib.h"

namespace industry_game
{
void RaylibRenderer::draw_circle(Position position, int radius, Color color,
                                 unsigned char alpha) const
{
    DrawCircle(position.x, position.y, radius, {color.r, color.g, color.b, alpha});
}
void RaylibRenderer::draw_rectangle(Position position, int width, int height, Color color,
                                    unsigned char alpha) const
{
    DrawRectangle(position.x, position.y, width, height, {color.r, color.g, color.b, alpha});
}
void RaylibRenderer::initialize(std::string_view name, int width, int height, int target_fps)
{
    InitWindow(width, height, name.data());
    SetTargetFPS(target_fps);
}
bool RaylibRenderer::window_should_close() const
{
    return WindowShouldClose();
}
void RaylibRenderer::close_window()
{
    CloseWindow();
}
void RaylibRenderer::begin_drawing()
{
    BeginDrawing();
}
void RaylibRenderer::end_drawing()
{
    EndDrawing();
}
void RaylibRenderer::clear_background(Color color)
{
    ClearBackground({color.r, color.g, color.b, 255});
}
bool RaylibRenderer::is_key_released(Key key)
{
    switch (key)
    {
    case Key::One:
        return IsKeyReleased(KEY_ONE);
    case Key::Two:
        return IsKeyReleased(KEY_TWO);
    case Key::Three:
        return IsKeyReleased(KEY_THREE);
    }
    return false;
}
} // namespace industry_game