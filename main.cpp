#include <iostream>
#include "BoardDisplay.hpp"
#include "adj_list.hpp"
#include "BFS.hpp"
#include "RandomBoard.hpp"

using namespace std;

int main()
{
    // Limits for how many snakes and ladders we can store
    const int MAX_SNAKES = 20;
    const int MAX_LADDERS = 20;

    int snakes[MAX_SNAKES][2];
    int ladders[MAX_LADDERS][2];
    int numSnakes = 0;
    int numLadders = 0;

    // ✅ Generate a NEW random configuration every run
    // This fills snakes/ladders arrays and also writes them to board.csv
    generateRandomBoard("board.csv",
                        snakes, numSnakes, MAX_SNAKES,
                        ladders, numLadders, MAX_LADDERS);

    // Create helper objects based on this random board
    BoardDisplay boardDisplay;
    adj_list graph(numSnakes, snakes, numLadders, ladders);
    BFS solver(&graph);

    int choice = -1;

    // Simple command-line menu loop
    while (true)
    {
        cout << "\n============================\n";
        cout << "   Snakes and Ladders Menu  \n";
        cout << "============================\n";
        cout << "1. Show board\n";
        cout << "2. Show shortest path from 1 to 100 (using BFS)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // handle invalid input (like letters)
        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 0)
        {
            cout << "Exiting... Goodbye!\n";
            break;
        }
        else if (choice == 1)
        {
            boardDisplay.printBoard2D(snakes, numSnakes, ladders, numLadders);
        }
        else if (choice == 2)
        {
            cout << "\nRunning BFS to find shortest path from 1 to 100...\n";
            solver.bfs(0); // vertex 0 = square 1
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
