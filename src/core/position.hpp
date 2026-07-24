#pragma once

namespace industry_game
{
struct Position
{
    double x;
    double y;
    bool operator==(const Position& other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Position& other) const
    {
        return !(*this == other);
    }
};
} // namespace industry_game