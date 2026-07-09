#include "raylib_renderer.hpp"

#include "raylib.h"

namespace industry_game
{
void RaylibRenderer::initialize(const char* name, int width, int height, int target_fps)
{
    InitWindow(width, height, name);
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