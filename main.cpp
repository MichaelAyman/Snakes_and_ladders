#include <iostream>
#include "adj_list.hpp"
#include "BFS.hpp"

using namespace std;

void printBoard2D(int snakes[][2], int numSnakes, int ladders[][2], int numLadders)
{
    cout << "Snakes and Ladders Board:" << endl
         << endl;

    for (int row = 9; row >= 0; row--)
    {
        if (row % 2 == 0)
        {
            // left to right
            for (int col = 0; col < 10; col++)
            {
                int cell = row * 10 + col;
                bool printed = false;

                for (int s = 0; s < numSnakes; s++)
                {
                    if (snakes[s][0] == cell)
                    {
                        cout << cell << "(S" << snakes[s][1] << ")\t";
                        printed = true;
                        break;
                    }
                }

                if (!printed)
                {
                    for (int l = 0; l < numLadders; l++)
                    {
                        if (ladders[l][0] == cell)
                        {
                            cout << cell << "(L" << ladders[l][1] << ")\t";
                            printed = true;
                            break;
                        }
                    }
                }

                if (!printed)
                    cout << cell << "\t";
            }
        }
        else
        {
            // right to left for zigzag pattern
            for (int col = 9; col >= 0; col--)
            {
                int cell = row * 10 + col;
                bool printed = false;

                for (int s = 0; s < numSnakes; s++)
                {
                    if (snakes[s][0] == cell)
                    {
                        cout << cell << "(S" << snakes[s][1] << ")\t";
                        printed = true;
                        break;
                    }
                }

                if (!printed)
                {
                    for (int l = 0; l < numLadders; l++)
                    {
                        if (ladders[l][0] == cell)
                        {
                            cout << cell << "(L" << ladders[l][1] << ")\t";
                            printed = true;
                            break;
                        }
                    }
                }

                if (!printed)
                    cout << cell << "\t";
            }
        }
        cout << endl
             << endl;
    }
}

int main()
{
    // Define snakes: from -> to (lower number)
    int snakes[][2] = {
        {16, 6},
        {47, 26},
        {49, 11},
        {56, 53},
        {62, 19},
        {64, 60},
        {87, 24},
        {93, 73},
        {95, 75},
        {98, 78}};
    int numSnakes = 10;

    // Define ladders: from -> to (higher number)
    int ladders[][2] = {
        {1, 38},
        {4, 14},
        {9, 31},
        {21, 42},
        {28, 84},
        {36, 44},
        {51, 67},
        {71, 91},
        {80, 99} // 99 is last index
    };
    int numLadders = 9;

    printBoard2D(snakes, numSnakes, ladders, numLadders);

    // Create graph with snakes and ladders
    adj_list g(numSnakes, snakes, numLadders, ladders);

    // Run BFS
    BFS solver(&g);
    solver.bfs(0);

    return 0;
}