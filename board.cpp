#include <assert.h>
#include <iostream>

#include "HeaderFiles/Board.h"
#include "HeaderFiles/Constants.h"

using namespace CONSTANTS;

class Board {
private:
    std::vector<std::vector<Tile>> m_board;
    int m_height, m_width;

public:
    Board::Board(int width, int height)
    : m_board(height), m_width(width), m_height(height) {
        assert(width > 1 && height > 1 && width % 2 == 0 && height % 2 == 0);
        assert(width < 43 && height < 31);
        
        for (auto row : m_board) {
            row = std::vector<Tile>(width, Tile::Empty);
        }

        // set starting spaces
        m_board[height/2-1][width/2-1] = Tile::White;
        m_board[height/2][width/2] = Tile::White;
        m_board[height/2][width/2-1] = Tile::Black;
        m_board[height/2-1][width/2] = Tile::Black;
    }

    int Board::getHeight() const {
        return m_height;
    }

    int Board::getWidth() const {
        return m_board[0].size();
    }

    bool Board::IsOnBoard(Position pos) {
        return (pos.x >= 0 && pos.x < m_width &&
                pos.y >= 0 && pos.y < m_height);
    }

    void Board::flipPieces(Position position, const Tile& tile);

    Tile Board::getTile(Position position);
    void Board::setTile(Position position, const Tile& tile);

    void Board::displayBoard() {
        std::cout << "\n\n    ";
 
        // Print x-axis labels across the top
        for(int i=0; i<m_width; i++) {
            std::cout << " " << x_to_label(i);
        }
 
        // Print horizontal bars and top-left/top-right corners across the top
        std::cout << "\n   " << TL_CORNER;
        for(int i = 0; i < m_width; i++) {
            std::cout << HORZ_BAR << HORZ_BAR;
        }
        std::cout << HORZ_BAR << TR_CORNER;
 
        std::cout << "\n";
 
        // Print vertical bars, y-axis labels, and the tiles of the board itself
        //  with different symbols for the 4 different types of tiles
        for(int i = 0; i < m_height; i++) {
            std::cout << " " << y_to_label(i) << " " << VERT_BAR;
            for(int j=0; j <m_width; j++) {
                std::cout << " ";
                switch(m_board[i][j]) {
                    case Tile::White:   
                        std::cout << YELLOW_BOLD << "■" << RESET_COLOR;
                        break;
                    case Tile::Black:   
                        std::cout << RED_BOLD << "■" << RED_BOLD;
                        break;
                    case Tile::Empty:   
                        std::cout << CYAN << "•" << RESET_COLOR;
                        break;
                    case Tile::Legal:   
                        std::cout << WHITE_BOLD << "○" << RESET_COLOR;
                        break;
                }   
            }
            std::cout << " " << VERT_BAR << " " << y_to_label(i) << "\n";
        }
 
        // Print horizontal bars and bottom-left/bottom-right corners across the bottom
        std::cout << "   " << BL_CORNER;
        for(int i=0; i<m_width; i++) {
           std::cout << HORZ_BAR << HORZ_BAR;
        }
        std::cout << HORZ_BAR << BR_CORNER;
 
        // Print x-axis labels across the bottom
        std::cout << "\n    ";
        for(int i=0; i<m_width; i++) {
            std::cout << " " << x_to_label(i);
        }
        std::cout << "\n\n";
    }

    int Board::countTiles(const Tile& tile);

    void Board::displayScores();
    void Board::display();

    std::vector<Position> Board::getLegalMoves(std::vector<Position> positions, Tile playerTile);
    std::vector<Position> Board::getPlayerTiles(Tile playerTile);

    void Board::updateLegalMoves(Tile player_tile);

    bool Board::canGameContinue();

    Board::~Board();
};