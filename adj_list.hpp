#ifndef ADJ_LIST_HPP
#define ADJ_LIST_HPP

class adj_list
{
private:
    int v;        // number of vertices (will be initialized in the cpp)
    int **adj;    // adjacency list (allocated in constructor)
    int *board;   // board representation with snakes and ladders

public:
    adj_list(int numSnakes, int snakes[][2], int numLadders, int ladders[][2]);
    ~adj_list();

    int *getNeighbors(int v);
    int getDegree(int v);
};

#endif // ADJ_LIST_HPP
