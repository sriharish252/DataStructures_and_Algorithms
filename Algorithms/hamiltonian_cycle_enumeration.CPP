// HAMILTONIAN CYCLE Problem
// Enumeration Problem
// Find all possible ways to cycle through the graph visiting every vertex only once
// Backtracking
// Time Complexity : O(n^n) , n-> no of vertices
// Recurrence Relation : T(n)=T(n-1)*n

#include<iostream>
using namespace std;

void display(int* path,int v) {
    for(int i=0;i<v;i++)
        cout<<path[i]<<" -> ";
    cout<<path[0];
    cout<<"\n";
}

int issafe(int* graph[],int* path,int v,int index,int vertex) {
    if(graph[path[index-1]][vertex]==1 && index<v) {    //Check if an edge exists btwn previous vertex
        for(int i=0;i<index;i++)                        // and selected vertex
            if(path[i]==vertex)                     //Check if selected vertex is unvisited
                return 0;
        return 1;                           //If for() loop runs fully, then vertex is unvisited
    }
    return 0;
}

void solve(int* graph[],int* path,int v,int index) {
    if(index==v && graph[path[v-1]][path[0]]==1)    //Check if all vertices are visited once AND if an
        display(path,v);                            //edge exists btwn the last vertex and the first vertex
    else {
        for(int i=0;i<v;i++) {
            if(issafe(graph,path,v,index,i)==1) {   //Check every vertex
                path[index]=i;                      //Selecting the vertex
                solve(graph,path,v,index+1);        //Explore every feasible path
                path[index]=-1;                     //Backtracking
            }
        }
    }
}


int main() {
    int v,e;
    cout<<"Enter no of Vertices and Edges:\n";
    cin>>v>>e;
    int *graph[v];                              //Adjacency Matrix
    int path[v];                                //Shows the vertices explored and the path taken
    for(int i=0;i<v;i++) {
        graph[i]=(int*)calloc(v,sizeof(int));   //calloc() will assign values to 0, hence malloc() is not used
        path[i]=-1;                             //Initializing to -1
    }
    cout<<"Enter Edge Connections (start notation from 0 to v-1):\n";
    int v1,v2;
    for(int i=0;i<e;i++) {
        cin>>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    for(int i=0;i<v;i++) {
        path[0]=i;                      //Assigning the starting node to path
        solve(graph,path,v,1);
    }                                   //revert() is not necessary after each new solve() coz in the
}                                       //descending phase of solve() we hv reassigned path[i]=-1
