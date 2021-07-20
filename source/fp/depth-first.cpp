//
//  depth-first.cpp
//  fp
//
//  Created by MAC on 20/06/2021.
//  Copyright © 2021 MAC. All rights reserved.
//

#include "depth-first.h"
#include <list>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

DFSGraph::DFSGraph(int V){
    // class Constructor
     this->V = V;
     adjList = new list<int>[V];
}

void DFSGraph::DFS_util(int v, bool visited[])
{
    // current node v is visited
    visited[v] = true;
    cout << v << " ";
   
    // recursively process all the adjacent vertices of the node
    list<int>::iterator i;
    for(i = adjList[v].begin(); i != adjList[v].end(); ++i)
        if(!visited[*i])
            DFS_util(*i, visited);
}

// DFS traversal
void DFSGraph::DFS()
{
    // initially none of the vertices are visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
   
    // explore the vertices one by one by recursively calling  DFS_util
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFS_util(i, visited);
}

void DFSGraph::addEdge(int v, int w){
    adjList[v].push_back(w); // Add w to v’s list.
}
void RunDFS(){
    DFSGraph gdfs(10);
    gdfs.addEdge(0, 1);
    gdfs.addEdge(0, 2);
    gdfs.addEdge(0, 3);
    gdfs.addEdge(0, 7);
    gdfs.addEdge(1, 2);
    gdfs.addEdge(1, 5);
    gdfs.addEdge(2, 4);
    gdfs.addEdge(3, 4);
    gdfs.addEdge(3, 9);
    gdfs.addEdge(4, 5);
    gdfs.addEdge(5, 6);
    gdfs.addEdge(5, 9);
    gdfs.addEdge(6, 8);
    gdfs.addEdge(6, 9);
    gdfs.addEdge(7, 8);
    gdfs.addEdge(8, 9);
    gdfs.addEdge(9, 9);
    
    
    cout << "Depth-first traversal for the given graph:"<<endl;
    auto start = high_resolution_clock::now();
    gdfs.DFS();
    auto stop = high_resolution_clock::now();
    duration<double> duration = stop -start;
    cout<<endl<<duration.count()<<endl;
}
