#include <assert.h>
#include <iostream>

#include "HeaderFiles/Board.h"
#include "HeaderFiles/Constants.h"
#include "HeaderFiles/helper.h"

using namespace CONSTANTS;

Board::Board(int width, int height)
: m_width(width), m_height(height), m_board(height) {
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

bool Board::isOnBoard(Position pos) {
    return (pos.x >= 0 && pos.x < m_width &&
            pos.y >= 0 && pos.y < m_height);
}

void flipPieces(Position position, const Tile& tile);

Tile getTile(Position position);
void setTile(Position position, const Tile& tile);

void Board::displayBoard() {
    std::cout << "\n\n    ";

    // Print x-axis labels across the top
    for(int i=0; i<m_width; i++) {
        std::cout << " " << xToLabel(i);
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
        std::cout << " " << yToLabel(i) << " " << VERT_BAR;
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
        std::cout << " " << VERT_BAR << " " << yToLabel(i) << "\n";
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
        std::cout << " " << xToLabel(i);
    }
    std::cout << "\n\n";
}

int countTiles(const Tile& tile);

void displayScores();
void display();

std::vector<Position> getLegalMoves(std::vector<Position> positions, Tile playerTile);
std::vector<Position> getPlayerTiles(Tile playerTile);

void updateLegalMoves(Tile player_tile);

bool canGameContinue();

Board::~Board() {
    std::cout << "Board Destroyed" << std::endl;
}