#include "Board.h"

// Abstract base class for players
class IPlayer {
public: 
    virtual Position getMove(Board& board, Tile& player_tile) = 0;
    virtual ~IPlayer() { }
};