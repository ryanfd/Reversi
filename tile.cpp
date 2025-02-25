#include <HeaderFiles/tile.h>

enum class Tile {
    white,
    black,
    empty,
    legal
};

struct Pos {
    int x;
    int y;
};

struct Direction {
    int dx;
    int dy;
};

struct DirToPos {
    Direction d;
    Pos loc;
};

const std::vector<Direction> DIRS = {
    {-1, 0},    // Left
    {-1, -1},   // Up-left
    {0, -1},    // Up
    {1, -1},    // Up-right
    {1, 0},     // Right
    {1, 1},     // Down-right
    {0, 1},     // Down
    {-1, 1}     // Down-left
};