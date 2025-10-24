#pragma once
#ifndef ADJ_LIST_HPP
#define ADJ_LIST_HPP

#include <iostream>

using namespace std;

class adj_list
{
private:
    int v = 100;              // number of vertices
    int **adj = new int *[v]; // adjacency list
    int *board;               // board representation with snakes and ladders
public:
    adj_list(int numSnakes, int snakes[][2], int numLadders, int ladders[][2]);
    ~adj_list();
    int *getNeighbors(int v);
    int getDegree(int v);
};

#endif // ADJ_LIST_HPP