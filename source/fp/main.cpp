#include <iostream>
#include <chrono>
#include "algs.h"
#include "Graph.h"
#include "depth-first.h"
#include "breadth-first.h"

using namespace std;
using namespace std::chrono;


A::algs project;


int main(int argc, const char* argv[]) {
    project.IS(1000);
    cout << endl;
    project.IS(2000);
    cout << endl;
    project.IS(3000);     cout << endl;
    project.IS(4000);
    cout << endl;
    project.IS(5000);
    cout << endl;
    project.IS(6000);
    cout << endl<<endl;
    
    project.BS(1000);
    cout << endl;
    project.BS(2000);
    cout << endl;
    project.BS(3000);
    cout << endl;
    project.BS(4000);
    cout << endl;
    project.BS(5000);
    cout << endl;
    project.BS(6000);
    cout << endl<<endl;
    
    project.SS(1000);
    cout << endl;
    project.SS(2000);
    cout << endl;
    project.SS(3000);
    cout << endl;
    project.SS(4000);
    cout << endl;
    project.SS(5000);
    cout << endl;
    project.SS(6000);
    cout << endl<<endl;
    
    project.QS(1000);
    cout << endl;
    project.QS(2000);
    cout << endl;
    project.QS(3000);
    cout << endl;
    project.QS(4000);
    cout << endl;
    project.QS(5000);
    cout << endl;
    project.QS(6000);
    cout << endl<<endl;
    
    project.MS(1000);
    cout << endl;
    project.MS(2000);
    cout << endl;
    project.MS(3000);
    cout << endl;
    project.MS(4000);
    cout << endl;
    project.MS(5000);
    cout << endl;
    project.MS(6000);
    cout << endl<<endl;
    
    project.BSearch(1000);
    cout<<endl;
    project.BSearch(2000);
    cout<<endl;
    project.BSearch(3000);
    cout<<endl;
    project.BSearch(4000);
    cout<<endl;
    project.BSearch(5000);
    cout<<endl;
    project.BSearch(6000);
    cout << endl<<endl;
    
    RunD();
    cout<<endl;
    
    RunDFS();
    cout<<endl;
    
    RunBFS();
    return 0;
}
