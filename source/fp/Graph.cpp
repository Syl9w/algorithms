#include <iostream>
#include <list>
#include<set>
#include<algorithm>
#include "Graph.h"
#include <chrono>
using namespace std;
using namespace std::chrono;


Graph::Graph(){
    n=0;
}


Graph::Graph(int nodeCount) {
   n = nodeCount;
   adjList = new list<node>[n];
}

void Graph::showList(int src, list<node> lt) {
         list<node> :: iterator i;
         node tempNode;

         for(i = lt.begin(); i != lt.end(); i++) {
            tempNode = *i;
            cout << "(" << src << ")---("<<tempNode.dest << "|"<<tempNode.cost<<")\t";
         }
         cout << endl;
      }
 

void Graph::addEdge(int source, int dest, int cost) {
         node newNode;
         newNode.dest = dest;
         newNode.cost = cost;
         adjList[source].push_back(newNode);
      }

void Graph::displayEdges() {
         for(int i = 0; i<n; i++) {
            list<node> tempList = adjList[i];
            showList(i, tempList);
         }
};

void dijkstra(Graph g, int *dist, int *prev, int start) {
   int n = g.n;
   for(int u = 0; u<n; u++) {
      dist[u] = 9999;   //set as infinity
      prev[u] = -1;    //undefined previous
   }
   dist[start] = 0;   //distance of start is 0
   set<int> S;       //create empty set S
   list<int> Q;
   for(int u = 0; u<n; u++) {
      Q.push_back(u);    //add each node into queue
   }
   while(!Q.empty()) {
      list<int> :: iterator i;
      i = min_element(Q.begin(), Q.end());
      int u = *i; //the minimum element from queue
      Q.remove(u);
      S.insert(u); //add u in the set
      list<node> :: iterator it;
      for(it = g.adjList[u].begin(); it != g.adjList[u].end();it++) {
         if((dist[u]+(it->cost)) < dist[it->dest]) { //relax (u,v)
            dist[it->dest] = (dist[u]+(it->cost));
            prev[it->dest] = u;
         }
      }
   }
}


void RunD(){
    
    int n=10;
    Graph mygraph(n);
    mygraph.addEdge(0,1,10);
    mygraph.addEdge(0,2,3);
    mygraph.addEdge(0,8,3);
    mygraph.addEdge(1,2,1);
    mygraph.addEdge(2,1,4);
    mygraph.addEdge(1,3,2);
    mygraph.addEdge(2,3,8);
    mygraph.addEdge(2,4,2);
    mygraph.addEdge(3,4,7);
    mygraph.addEdge(4,3,9);
    mygraph.addEdge(4, 5, 5);
    mygraph.addEdge(4, 6, 1);
    mygraph.addEdge(6, 5, 1);
    mygraph.addEdge(6, 7, 3);
    mygraph.addEdge(7, 3, 1);
    mygraph.addEdge(8, 3, 2);
    mygraph.addEdge(8, 9, 4);
    cout<<"\nDijkstra algorithm with "<<n<<" vertices: ";
    mygraph.displayEdges();
    cout<<"\n\n";
    int dist[n];
    int prev[n];
    
    auto start = high_resolution_clock::now();
    dijkstra(mygraph, dist, prev,0);
    auto stop = high_resolution_clock::now();
    duration<double> duration = stop - start;
    
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl<<duration.count()<<" sec."<<endl;
}
