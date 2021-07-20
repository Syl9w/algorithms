#include<iostream>
#include <list>
#include <chrono>
using namespace std;

// This class represents a directed graph using
// adjacency list representation
class BFSGraph
{
    int V; // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;
public:
    BFSGraph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    void BFS(int s);
};


void RunBFS();
