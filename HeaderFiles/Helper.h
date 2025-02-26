#include <string>

// Function that converts an x-axis int into its char label:
// ex. 0, 1, 2, 3 -> '1', '2', '3', '4'
char xToLabel(int x);
 
// Function that converts a y-axis int into its char label"
// ex. 0, 1, 2, 3 -> 'a', 'b', 'c', 'd'
char yToLabel(int y);
 
// Function that converts an x-axis char label into its int
// ex. '1', '2', '3', '4' -> 0, 1, 2, 3
int labelToX(char x);
 
// Function that converts a y-axis char label into its int
// ex. 'a', 'b', 'c', 'd' -> 0, 1, 2, 3
int labelToY(char y);

// Clean input when asking to play again
std::string cleanInput(const std::string& s);