// M-COLOURING Problem
// Enumeration Problem
// Find all possible colour combinations for 'v' vertiices in a given graph with 'm' colours,
// such that no two adjacent vertices have the same colour.
// Backtracking
// Time Complexity : O(m^n)
// Recurrence Relation : T(n)=T(n-1)*m  , n refers to the no of Vertices, m -> no of Colours

// Author : Sri Harish

#include<iostream>
using namespace std;

void display(int* soln,int v) {
    cout<<"Vertex  Colour\n";                   //Column Headings
    for(int i=0;i<v;i++)
        cout<<"  V"<<i<<"    "<<soln[i]<<endl;  //Spaces are just for some elegance in the output
    cout<<endl;
}

int issafe(int* graph[],int* soln,int v,int vertex,int colour) {
    if(vertex<v) {
        for(int i=0;i<v;i++) {
            if(graph[vertex][i]==1 && soln[i]==colour)  //Check if adjacent vertex has same colour
                return 0;
        }
        return 1;
    }
    return 0;
}

void solve(int* graph[],int soln[],int v,int m,int vertex) {
    if(vertex==v)           //if true, then all vertices are coloured
        display(soln,v);
    else {
        for(int i=0;i<m;i++) {                          //Exploring every colour path
            if(issafe(graph,soln,v,vertex,i)==1) {
                soln[vertex]=i;
                solve(graph,soln,v,m,vertex+1);
                soln[vertex]=-1;
            }
        }
    }
}


int main() {
    int v,e;
    cout<<"Enter the no of Vertices and Edges :\n";
    cin>>v>>e;
    int* graph[v];                                  //graph[][] is the Adjacency Matrix, i.e., Graph
    int soln[v];                                 //soln[] shows which colour is assigned to each vertex
    for(int i=0;i<v;i++) {
        graph[i]=(int*)calloc(v,sizeof(int));
        soln[i]=-1;                             //Setting the initial values as -1
    }
    cout<<"Enter the Graph Edge points (start notation from V0):\n"; //Have Vertex nos from '0' to 'v-1'
    int v1,v2;
    for(int i=0;i<e;i++) {
        cin>>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    cout<<"Enter the no of Colours : ";
    int m;
    cin>>m;
    solve(graph,soln,v,m,0);
}

/*      PLAIN CODE

#include<iostream>
using namespace std;

void display(int* soln,int v) {
    cout<<"Vertex  Colour\n";
    for(int i=0;i<v;i++)
        cout<<"  V"<<i<<"    "<<soln[i]<<endl;
    cout<<endl;
}

int issafe(int* graph[],int* soln,int v,int vertex,int colour) {
    if(vertex<v) {
        for(int i=0;i<v;i++) {
            if(graph[vertex][i]==1 && soln[i]==colour)
                return 0;
        }
        return 1;
    }
    return 0;
}

void solve(int* graph[],int soln[],int v,int m,int vertex) {
    if(vertex==v)
        display(soln,v);
    else {
        for(int i=0;i<m;i++) {
            if(issafe(graph,soln,v,vertex,i)==1) {
                soln[vertex]=i;
                solve(graph,soln,v,m,vertex+1);
                soln[vertex]=-1;
            }
        }
    }
}


int main() {
    int v,e;
    cout<<"Enter the no of Vertices and Edges :\n";
    cin>>v>>e;
    int* graph[v];
    int soln[v];
    for(int i=0;i<v;i++) {
        graph[i]=(int*)calloc(v,sizeof(int));
        soln[i]=-1;
    }
    cout<<"Enter the Graph Edge points (start notation from V0):\n";
    int v1,v2;
    for(int i=0;i<e;i++) {
        cin>>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    cout<<"Enter the no of Colours : ";
    int m;
    cin>>m;
    solve(graph,soln,v,m,0);
}
*/

// Author : Sri Harish
// https://github.com/sriharish252
// https://www.linkedin.com/in/sri-harish
