[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Vinh Tran

## Description
My program allows for the user to add vertices and edges from a graph to my class 
then print the prim's minimum spanning tree.

Briefly describe what your program does and how the code is structured.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity          |
|----------------------|--------------------------|
| Insert in MinHeap    | O(log n)                 |
| Extract Min          | O(log n)                 |
| Decrease Key         | O(log n)                 |
| Prim’s MST Overall   | O((Vert*Edge) * (log v)) |

_Explain why your MST implementation has the above runtime._

It loops through every Vertex and for every vertex, it runs through every edge.
It also Heapifys every time the edge is called that hasn't been already been called.

## Test Case Description

Input:      
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);

Adds 0-1 with a weight of (2)

leaving 0 - 3 (6)
adding
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);

Adds 1 - 2 (3)

leaving 1 - 4 (5)
        0 - 3 (6)
        1 - 3 (8)
adding
g.addEdge(2, 4, 7);

Adds 1 - 4 (5)

leaving 0 - 3 (6)
        1 - 3 (8)
adding
g.addEdge(3, 4, 9);

Adds 0 - 3 (6)

Final of
0 - 1 (2)
1 - 2 (3)
0 - 3 (6)
1 - 4 (5)

