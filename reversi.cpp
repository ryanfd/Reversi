#include <iostream>

#include "HeaderFiles/Board.h"
#include "HeaderFiles/Constants.h"

int main()
{
    std::cout << "Welcome to text-based Reversi!" << std::endl;
    Board board(CONSTANTS::DEFAULT_BOARD_WIDTH, CONSTANTS::DEFAULT_BOARD_HEIGHT);
    board.displayBoard();
}