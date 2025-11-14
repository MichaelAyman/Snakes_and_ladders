#include "RandomBoard.hpp"
#include <fstream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

void generateRandomBoard(const char* filename,
                         int snakes[][2], int& numSnakes, int maxSnakes,
                         int ladders[][2], int& numLadders, int maxLadders)
{
    // Seed RNG once per run
    std::srand(std::time(0));

    // You can tune these
    int desiredSnakes  = 8;  // for example
    int desiredLadders = 8;  // for example

    if (desiredSnakes > maxSnakes)  desiredSnakes  = maxSnakes;
    if (desiredLadders > maxLadders) desiredLadders = maxLadders;

    // Track which squares are already used as heads/tails/bottoms/tops
    bool used[101];
    for (int i = 0; i <= 100; i++)
        used[i] = false;

    numSnakes = 0;
    numLadders = 0;

    const int MIN_SQUARE = 1;
    const int MAX_SQUARE = 99; // don't use 100 in snakes/ladders arrays

    // -------- Generate snakes (from > to) --------
    while (numSnakes < desiredSnakes)
    {
        int head = 5 + (std::rand() % (MAX_SQUARE - 4)); // avoid too small heads
        int tail = MIN_SQUARE + (std::rand() % (head - MIN_SQUARE)); // < head

        if (head == tail) continue;
        if (used[head] || used[tail]) continue;

        snakes[numSnakes][0] = head; // from (head)
        snakes[numSnakes][1] = tail; // to   (tail)
        used[head] = true;
        used[tail] = true;
        numSnakes++;
    }

    // -------- Generate ladders (from < to) --------
    while (numLadders < desiredLadders)
    {
        int bottom = MIN_SQUARE + (std::rand() % (MAX_SQUARE - 10)); // keep room above
        int top    = bottom + 1 + (std::rand() % (MAX_SQUARE - bottom)); // > bottom

        if (top == bottom) continue;
        if (used[bottom] || used[top]) continue;

        ladders[numLadders][0] = bottom; // from (bottom)
        ladders[numLadders][1] = top;    // to   (top)
        used[bottom] = true;
        used[top] = true;
        numLadders++;
    }

    // -------- Write them to CSV file --------
    std::ofstream file(filename);
    if (!file.is_open())
    {
        return; // if it fails, we still have arrays in memory
    }

    // Format: S,from,to   or   L,from,to
    for (int i = 0; i < numSnakes; i++)
    {
        file << "S," << snakes[i][0] << "," << snakes[i][1] << "\n";
    }

    for (int i = 0; i < numLadders; i++)
    {
        file << "L," << ladders[i][0] << "," << ladders[i][1] << "\n";
    }

    file.close();
}
