#include <HeaderFiles/tile.h>

// class Board {
// public:
    // Board(int width, int height);

    class Board;

    // int getWidth() const;
    // int getHeight() const;

    bool isOnBoard(Position position);
    void flipPieces(Position position, const Tile& tile);

    Tile getTile(Position position);
    void setTile(Position position, const Tile& tile);

    void displayBoard();

    int countTiles(const Tile& tile);

    void displayScores();
    void display();

    std::vector<Position> getLegalMoves(std::vector<Position> positions, Tile playerTile);
    std::vector<Position> getPlayerTiles(Tile playerTile);

    void updateLegalMoves(Tile player_tile);

    bool canGameContinue();

    // ~Board();
// };