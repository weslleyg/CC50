/****************************************************************************
 * sudoku.h
 *
 * CC 50
 * Pset 4
 *
 * Compile-time options for the game of Sudoku.
 ***************************************************************************/

// game's author
#define AUTHOR "Weslley"

// game's title
#define TITLE "Sudokuuuuu"

// banner's colors
#define FG_BANNER COLOR_CYAN
#define BG_BANNER COLOR_BLACK

// grid's colors
#define FG_GRID COLOR_GREEN
#define BG_GRID COLOR_BLACK

// border's colors
#define FG_BORDER COLOR_WHITE
#define BG_BORDER COLOR_GREEN

// logo's colors
#define FG_LOGO COLOR_GREEN
#define BG_LOGO COLOR_BLACK

//in game colors
#define FG_INIT COLOR_BLUE
#define BG_INIT COLOR_BLACK

#define FG_WON COLOR_GREEN
#define BG_WON COLOR_BLACK

#define FG_WARN COLOR_RED
#define BG_WARN COLOR_BLACK

// nicknames for pairs of colors
enum { PAIR_BANNER = 1, PAIR_GRID, PAIR_BORDER, PAIR_LOGO, PAIR_WON, PAIR_INIT, PAIR_WARN};
