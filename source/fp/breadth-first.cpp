#include "breadth-first.h"
#include <iostream>
#include <list>
#include <chrono>
using namespace std;
using namespace std::chrono;

BFSGraph::BFSGraph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void BFSGraph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void BFSGraph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void RunBFS(){
    BFSGraph g(10);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 5);
    g.addEdge(0, 6);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 9);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 8);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 3);
    g.addEdge(9, 6);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 0) \n";
    auto start = high_resolution_clock::now();
    g.BFS(0);
    auto stop = high_resolution_clock::now();
    duration<double> duration = stop - start;
    cout<<endl<<duration.count()<<endl;
    
}
