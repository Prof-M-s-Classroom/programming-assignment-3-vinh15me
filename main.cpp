#include <iostream>
#include "graph.h"
#include "heap.h"
int main() {

    /*

    MinHeap p(5);

    p.insert(2,5);
    p.insert(1,6);
    p.insert(3,3);
    p.decreaseKey(1,2);
    p.print();
    printf("Key of Min: %d\n",p.getKeyOfMin());
    printf("Vertex of Min: %d\n", p.getVertexOfMin());
    printf("Extracting of Min: %d\n", p.extractMin());
    p.extractMin();
    p.print();
    printf("\n");
    printf("%d",p.isInMinHeap(1));
    printf("\n");
    printf("%d",p.isInMinHeap(2));
    */




    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(0, 4, 9);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 4);

    //doens't go backwards
    //duplicate numbers fucks everythign
    g.primMST();
    return 0;
}