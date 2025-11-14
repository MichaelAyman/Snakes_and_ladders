#include "BoardDisplay.hpp"
#include <iostream>
using namespace std;

void BoardDisplay::printBoard2D(int snakes[][2], int numSnakes,
                                int ladders[][2], int numLadders)
{
    cout << "\nSnakes and Ladders Board\n\n";

    for (int row = 9; row >= 0; row--)
    {
        bool leftToRight = (row % 2 == 0);

        for (int col = 0; col < 10; col++)
        {
            int realCol = leftToRight ? col : 9 - col;
            int cell = row * 10 + realCol + 1; // convert to 1-indexed tile
            bool printed = false;

            // Check for snake heads
            for (int s = 0; s < numSnakes; s++)
            {
                if (snakes[s][0] == cell)
                {
                    cout << cell << "(S->" << snakes[s][1] << ")\t";
                    printed = true;
                    break;
                }
            }
            if (printed) continue;

            // Check for ladders
            for (int l = 0; l < numLadders; l++)
            {
                if (ladders[l][0] == cell)
                {
                    cout << cell << "(L->" << ladders[l][1] << ")\t";
                    printed = true;
                    break;
                }
            }
            if (printed) continue;

            cout << cell << "\t";
        }
        cout << "\n\n";
    }
}
