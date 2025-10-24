#include "BFS.hpp"
#include "Queue.hpp"
#include <iostream>

using namespace std;

void BFS::bfs(int startVertex)
{
    int *visited = new int[100];
    int *parent = new int[100];

    for (int i = 0; i < 100; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
    }

    Queue q(100);
    visited[startVertex] = 1;
    q.enqueue(startVertex);

    while (!q.isEmpty())
    {
        int current = q.dequeue();

        int *neighbors = graph->getNeighbors(current);
        int count = graph->getDegree(current);

        for (int i = 0; i < count; i++)
        {
            int next = neighbors[i];

            if (!visited[next])
            {
                visited[next] = 1;
                parent[next] = current;
                q.enqueue(next);

                if (next == 99)
                {
                    cout << "Reached 100!" << endl;

                    int path[100];
                    int idx = 0;
                    int crawl = 99;

                    while (crawl != -1)
                    {
                        path[idx++] = crawl;
                        crawl = parent[crawl];
                    }

                    cout << "Shortest path: ";
                    for (int i = idx - 1; i >= 0; i--)
                    {
                        cout << path[i] + 1;
                        if (i != 0)
                            cout << " -> ";
                    }
                    cout << endl;

                    delete[] visited;
                    delete[] parent;
                    return;
                }
            }
        }
    }

    cout << "No path found!" << endl;
    delete[] visited;
    delete[] parent;
}
