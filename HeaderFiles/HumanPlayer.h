#include <string>

#include "IPlayer.h"

class HumanPlayer : public IPlayer {
public: 
    // Cleans up the trailing and leading whitespace from a string
    std::string cleanString(const std::string& s);
    
    // Method that checks whether or not a user's input is valid given the list of legal moves
    bool isInputValid(const std::string& s, const std::vector<Position>& legal_moves);
    
    // Method to get move from user
    Position getMove(Board& board, Tile& player_tile);
    
    ~HumanPlayer();
};