#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int vertices;
    bool adj[MAX][MAX];
} Graph;

Graph *createGraph(int v) {
    Graph *g = malloc(sizeof(Graph));
    g->vertices = v;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; ++j) {
            g->adj[i][j] = false;
        }
    }

    return g;
}

void destroyGraph(Graph *g) {
    free(g);
}

void addEdge(Graph *g, int row, int col) {
    g->adj[row][col] = true;
}

void removeEdge(Graph *g, int row, int col) {
    g->adj[row][col] = false;
}

void bfsGraph(Graph *g, int start) {
    int vert = g->vertices;
    int visited[vert];

    for (int i = 0; i < vert; i++) {
        visited[i] = false;
    }

    int queue[vert];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    while (front != rear) {
        start = queue[front++];
        printf("%d\t", start);

        for (int i = 0; i < vert; i++) {
            if (g->adj[start][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    Graph *myGraph = createGraph(4);
    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 2);
    addEdge(myGraph, 1, 2);
    addEdge(myGraph, 2, 3);
    addEdge(myGraph, 3, 1);
    addEdge(myGraph, 3, 2);
    bfsGraph(myGraph, 0);
    destroyGraph(myGraph);
    return 0;
}