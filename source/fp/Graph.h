#include <iostream>
#include <list>
#include<set>
#include<algorithm>
#include <chrono>
using namespace std;

typedef struct nodes {
   int dest;
   int cost;
}node;

class Graph {
   int n;
   list<node> *adjList;
   private:
    void showList(int src, list<node> lt);

   public:
      Graph();

      Graph(int nodeCount);

        void addEdge(int source, int dest, int cost);

        void displayEdges();
    
        friend void dijkstra(Graph g, int *dist, int *prev, int start);
};

void dijkstra(Graph g, int *dist, int *prev, int start);
   

void RunD();
