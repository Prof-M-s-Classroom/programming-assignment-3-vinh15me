#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"

class Graph {
public:
    Graph(int vertices): numVertices(vertices) {
        adjMatrix = new int *[vertices];
        for (int i = 0; i < vertices; ++i) {
            adjMatrix[i] = new int[vertices];
        }
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                adjMatrix[i][j] = INT_MAX;
                if (i == j) {
                    adjMatrix[i][j] = 0;
                }
            }
        }
    }

    ~Graph() {
        delete[] adjMatrix;
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
    void primMST() {



        MinHeap* min_heap = new MinHeap(numVertices);
        for (int x = 0; x < numVertices; ++x) {
            for (int y = x+1; y < numVertices; ++y) {
                min_heap->decreaseKey(y,adjMatrix[x][y],x);
            }
        }

        printf("\n");
        min_heap->print();

    };  // Must print MST edges and total weight

    int** getAdjMatrix() {
        return adjMatrix;
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif