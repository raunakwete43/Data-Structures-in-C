#include <stdio.h>

#define V 4
#define INF 999

void printSolution(int dist[][V])
{
    int i, j;
    printf("The following matrix shows the shortest distance between every pair of vertices\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
            {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall(int dist[][V])
{
    int i, j, k;
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if ((i == j) || (i == k) || (j == k))
                    continue;
                int temp = dist[i][k] + dist[k][j];
                if (temp < dist[i][j])
                    dist[i][j] = temp;
            }
        }
        printSolution(dist);
    }
}

int main()
{
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}};

    floydWarshall(graph);

    return 0;
}