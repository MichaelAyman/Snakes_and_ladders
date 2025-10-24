#ifndef BFS_HPP
#define BFS_HPP
#include "adj_list.hpp"

class BFS
{
private:
    adj_list *graph;

public:
    BFS(adj_list *g) : graph(g) {};
    void bfs(int startVertex);
};

#endif // BFS_HPP