#include <stdio.h>
#include <stdbool.h>

#define V 4
#define MAX 999

int minVertex(int dist[], bool sptSet[])
{
    int min = MAX, index = 0;
    for (int i = 0; i < V; i++)
    {
        if (sptSet[i] == false && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
    {
        sptSet[i] = false;
        dist[i] = MAX;
    }

    dist[src] = 0;

    for (int i = 0; i < V; i++)
    {
        int minV = minVertex(dist, sptSet);

        sptSet[minV] = true;

        for (int j = 0; j < V; j++)
        {
            if (!sptSet[j] && graph[minV][j] != 0 && dist[minV] != MAX && (dist[minV] + graph[minV][j] < dist[j]))
            {
                dist[j] = dist[minV] + graph[minV][j];
            }
        }
    }

    printSolution(dist);
}

int main(int argc, char const *argv[])
{
    int graph[V][V] = {
        {0, 3, 2, 0},
        {3, 0, 8, 4},
        {2, 8, 0, 6},
        {0, 4, 6, 0}};

    dijkstra(graph, 0);
    return 0;
}
