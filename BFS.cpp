#include "BFS.hpp"

#include "BFS.hpp"

void BFS::bfs(int startVertex)
{
    const int V = 100;
    bool *visited = new bool[V];
    int *parent = new int[V];
    int *queue = new int[V];
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front != rear)
    {
        int current = queue[front++];

        if (current == 99)
            break; // We reached the end!

        int degree = graph->getDegree(current);
        int *neighbors = graph->getNeighbors(current);

        for (int i = 0; i < degree; i++)
        {
            int next = neighbors[i];

            if (!visited[next])
            {
                visited[next] = true;
                parent[next] = current;
                queue[rear++] = next;
            }
        }
    }

    // Reconstruct fastest path
    int path[V];
    int idx = 0;
    int crawl = 99;

    while (crawl != -1)
    {
        path[idx++] = crawl;
        crawl = parent[crawl];
    }

    cout << "Minimum moves path:" << endl;
    for (int i = idx - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i > 0)
            cout << " -> ";
    }
    cout << endl;

    delete[] visited;
    delete[] parent;
    delete[] queue;
}
