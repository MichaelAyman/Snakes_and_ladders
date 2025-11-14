#ifndef RANDOM_BOARD_HPP
#define RANDOM_BOARD_HPP

// Generates random snakes and ladders,
// fills the arrays, sets numSnakes and numLadders,
// and writes them to a CSV file (e.g. "board.csv").
void generateRandomBoard(const char* filename,
                         int snakes[][2], int& numSnakes, int maxSnakes,
                         int ladders[][2], int& numLadders, int maxLadders);

#endif // RANDOM_BOARD_HPP
