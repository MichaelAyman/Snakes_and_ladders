#include "adj_list.hpp"

adj_list::adj_list(int numSnakes, int snakes[][2], int numLadders, int ladders[][2])
{
    // initialize number of vertices here
    v = 100;

    // allocate adjacency list and board
    adj = new int *[v];
    board = new int[v];

    // initialize board
    for (int i = 0; i < v; i++)
        board[i] = i;

    // Apply snakes (convert 1-based to 0-based)
    for (int i = 0; i < numSnakes; i++)
        board[snakes[i][0] - 1] = snakes[i][1] - 1;

    // Apply ladders (convert 1-based to 0-based)
    for (int i = 0; i < numLadders; i++)
        board[ladders[i][0] - 1] = ladders[i][1] - 1;

    // Build adjacency list
    for (int i = 0; i < v; i++)
    {
        int maxMoves = (i <= 93) ? 6 : (99 - i);
        adj[i] = new int[maxMoves];

        for (int j = 0; j < maxMoves; j++)
        {
            int nextSquare = i + j + 1;
            adj[i][j] = board[nextSquare];
        }
    }
}

adj_list::~adj_list()
{
    for (int i = 0; i < v; i++)
        delete[] adj[i];

    delete[] adj;
    delete[] board;
}

int *adj_list::getNeighbors(int v)
{
    return adj[v];
}

int adj_list::getDegree(int v)
{
    if (v <= 93)
        return 6;
    return 99 - v;
}
