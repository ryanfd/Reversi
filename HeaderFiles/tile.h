#include <vector>

// Enumerated class for the types of Tiles
enum class Tile;

// Structure for two ints that represent to x and y coordinate points of a tile
struct Pos;

// Structure for a direction used in the legal move and board flipping algorithms
struct Direction;

// Structure that contains a target position and a direction to that position
// Used for "segments" of tiles to be flipped to the opposite color in the flipping algorithm
struct DirToPos;

// Constant global variable that holds all the 4 cardinal + 4 diagonal directions 
const std::vector<Direction> DIRS;