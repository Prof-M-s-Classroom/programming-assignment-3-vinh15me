#ifndef GRAPH_H
#define GRAPH_H
#include <algorithm>

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
        for (int i = 0; i < numVertices; ++i) {
            delete[] adjMatrix[i];
        }
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
    void primMST() {
        MinHeap* min_heap = new MinHeap(numVertices);

        int* previousVertex = new int[numVertices];
        int* weights = new int[numVertices];

        min_heap->insert(0, 0);

        int* vertexVisited = new int[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            vertexVisited[i] = 0;
            previousVertex[i] = -1;
            weights[i] = INT_MAX;
        }

        int vertexRemoved = min_heap->extractMin();//intinal call to remove zero and add edges
        weights[vertexRemoved] = 0;
        for (int i = vertexRemoved+1; i < numVertices; ++i) {
            /*
            min_heap->decreaseKey(i, adjMatrix[vertexRemoved][i]);
            if (min_heap->getKey(i) > adjMatrix[vertexRemoved][i]) {
                previousVertex[i] = vertexRemoved;
            }
            */
            if (min_heap->isInMinHeap(i)) {
                min_heap->decreaseKey(i, adjMatrix[vertexRemoved][i]);
                if (min_heap->getKey(i) > adjMatrix[vertexRemoved][i]) {
                    if (vertexVisited[vertexRemoved] != 1) {
                        previousVertex[i] = vertexRemoved;
                    }
                }
            }
            else if (adjMatrix[vertexRemoved][i] != INT_MAX) {
                printf("Key: %d\n", adjMatrix[vertexRemoved][i]);
                printf("Vertex Origin: %d\n", vertexRemoved);
                printf("Vertex Target: %d\n\n", i);
                min_heap->insert(i,adjMatrix[vertexRemoved][i]);
                previousVertex[i] = vertexRemoved;
            }

        }
        printf("\n");
        min_heap->print();
        printf("\n");

        for (int i = 1; i < numVertices; ++i) {
            int temp = min_heap->getKeyOfMin();
            vertexRemoved = min_heap->extractMin();
            while (vertexVisited[vertexRemoved] == 1) {
                temp = min_heap->getKeyOfMin();
                vertexRemoved = min_heap->extractMin();
            }
            printf("Array of Vertex Visited: ");
            for (int y = 0; y < numVertices; ++y) {
                 printf("%d ", vertexVisited[y]);
            }
            printf("\nKey of Min: %d\n", temp);
            printf("Vertex Current: %d\n\n", i);
            weights[vertexRemoved] = temp;
            vertexVisited[vertexRemoved] = 1;
            for (int x = vertexRemoved+1; x < numVertices; ++x) {
                /*
                min_heap->decreaseKey(i, adjMatrix[vertexRemoved][i]);
                if (min_heap->getKey(i) > adjMatrix[vertexRemoved][i]) {
                    previousVertex[i] = vertexRemoved;
                }
                */
                printf("Is X in minHeap? %d\n",min_heap->isInMinHeap(x));
                printf("X: %d\n", x);
                printf("Is X visited? %d\n",vertexVisited[x]);

                printf("Visited ");
                for (int y = 0; y < numVertices; ++y) {
                    printf("%d ", vertexVisited[y]);
                }
                printf("\n");

                if (vertexVisited[x] == 1) {

                    printf("Skipped\n");
                    printf("Skipped\n");
                }
                else if (min_heap->isInMinHeap(x)) {
                    printf("Decreased Key\n");
                    if (min_heap->getKey(x) > adjMatrix[vertexRemoved][x]) {
                        previousVertex[x] = vertexRemoved;
                    }
                    min_heap->decreaseKey(x, adjMatrix[vertexRemoved][x]);
                }
                else if (adjMatrix[vertexRemoved][x] != INT_MAX) {
                    printf("Inserted\n");
                    min_heap->insert(x,adjMatrix[vertexRemoved][x]);

                    previousVertex[x] = vertexRemoved;
                }
            }
            printf("\n");
            min_heap->print();
            printf("\n\n");
        }

        for (int i = 1; i < numVertices; ++i) {
            printf("%d -- %d (%d)\n", previousVertex[i], i, weights[i]);
        }



    };  // Must print MST edges and total weight

    int** getAdjMatrix() {
        return adjMatrix;
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif