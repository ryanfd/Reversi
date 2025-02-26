#include <vector>

// Types of Tiles
enum Tile {
    White,
    Black,
    Empty,
    Legal
};

// Structure for two ints that represent to x and y coordinate points of a tile
struct Position {
    int x;
    int y;
};

// Structure for a direction used in the legal move and board flipping algorithms
struct Direction {
    int dx;
    int dy;
};

// Structure that contains a target position and a direction to that position
// Used for "segments" of tiles to be flipped to the opposite color in the flipping algorithm
struct DirToPos {
    Direction dir;
    Position pos;
};

// Constant global variable that holds all the 4 cardinal + 4 diagonal directions 
const std::vector<Direction> DIRS {
    {-1, 0},    // Left
    {-1, -1},   // Up-left
    {0, -1},    // Up
    {1, -1},    // Up-right
    {1, 0},     // Right
    {1, 1},     // Down-right
    {0, 1},     // Down
    {-1, 1}     // Down-left
};