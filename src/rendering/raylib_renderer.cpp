#include "raylib_renderer.hpp"

namespace industry_game
{
void RaylibRenderer::initialize(const char* name, int width, int height, int target_fps)
{
    name_ = name;
    width_ = width;
    height_ = height;
    target_fps_ = target_fps;
    InitWindow(width_, height_, name_);
    SetTargetFPS(target_fps_);
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
} // namespace industry_game