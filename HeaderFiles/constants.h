#include <string>

// Foreground text colors
const std::string RED_BOLD = "\033[1;31m";
const std::string YELLOW_BOLD = "\033[1;33m";
const std::string CYAN = "\033[0;36m";
const std::string WHITE_BOLD = "\033[1;37m";
const std::string RESET_COLOR = "\033[0m";
 
// Characters for the edges of the board-- this doesn't compile with these characters
const std::string TL_CORNER = "╔";
const std::string TR_CORNER = "╗";
const std::string BL_CORNER = "╚";
const std::string BR_CORNER = "╝";
const std::string VERT_BAR = "║";
const std::string HORZ_BAR = "═";
 
// Delay between board displays for more natural user experience
const int DELAY_MILLISECONDS = 1000;