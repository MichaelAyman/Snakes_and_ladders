#ifndef BOARD_DISPLAY_HPP
#define BOARD_DISPLAY_HPP

class BoardDisplay
{
public:
    // Displays the Snakes and Ladders board in 2D form
    void printBoard2D(int snakes[][2], int numSnakes,
                      int ladders[][2], int numLadders);
};

#endif // BOARD_DISPLAY_HPP
