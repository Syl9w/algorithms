#include <iostream>
#include <list>
#include <chrono>
using namespace std;
using namespace std::chrono;
//graph class for DFS travesal
class DFSGraph
{
    int V;    // No. of vertices
    list<int> *adjList;    // adjacency list
    void DFS_util(int v, bool visited[]);  // A function used by DFS
    public:
    // class Constructor
    DFSGraph(int V);
    // function to add an edge to graph
    void addEdge(int v, int w);
    void DFS();    // DFS traversal function
};

void RunDFS();
