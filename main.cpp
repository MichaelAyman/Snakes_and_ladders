#include <iostream>
#include "adj_list.hpp"
#include "BFS.hpp"

using namespace std;

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
    int numSnakes = sizeof(snakes) / sizeof(snakes[0]);

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
    int numLadders = sizeof(ladders) / sizeof(ladders[0]);

    // Create graph with snakes and ladders
    adj_list g(numSnakes, snakes, numLadders, ladders);

    // Run BFS
    BFS solver(&g);
    solver.bfs(0);

    return 0;
}