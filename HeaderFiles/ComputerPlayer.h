#include "IPlayer.h"

// Computer player class that extends abstract base Player class
class ComputerPlayer : public IPlayer {
public: 
    
    // Structure that holds a specific potential move and the "value" associated with that move--
    // that is, the number of tiles the player would have after playing that move
    struct MoveValue {
        Position move;
        int value;
    };
    
    // Returns whether or not a Position is a corner space on a given board, used for the Computer
    // player as it prioritizes corner moves
    bool isCornerMove(Position& move, Board& board);
    
    // Method that returns the Position of the highest value move from the vector of moves values
    Position getHighestValMove(std::vector<MoveValue> moves_values);
    
    // Method to get move from computer
    Position getMove(Board& board, Tile& player_tile);
    
    ~ComputerPlayer();
};