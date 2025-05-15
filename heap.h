#ifndef HEAP_H
#define HEAP_H
#include <ranges>

class MinHeap {
public:
    MinHeap(int capacity): capacity(capacity) {
        size = 0;
        keyArray = new int[capacity];
        heapArray = new int[capacity];
        position = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            position[i] = -1;
            keyArray[i] = INT_MAX;
            heapArray[i] = i;
        }
        keyArray[0] = 0;
    }
    ~MinHeap();
    void insert(int vertex, int key){

    }

    int extractMin() {
    }

    void decreaseKey(int vertex, int newKey, int old) {
        if (keyArray[vertex] > newKey){
        keyArray[vertex] = newKey;
        position[vertex] = old;
        }
    }

    bool isInMinHeap(int vertex);
    bool isEmpty() {
        return size == 0.;
    }

    void minHeapify(int idx) {
    }


    void print() {
        for (int i = 1; i < capacity; i++) {
            printf("%d -- %d (%d)\n", position[i], i,keyArray[i]);
        }
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding weight values to other vertices
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

};

#endif