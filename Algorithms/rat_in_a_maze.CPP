// RAT IN A MAZE Problem
// Enumeration Problem
// Backtracking
// Time Complexity : O(2^n)
// Recurrence Relation : T(n)=T(n-1)*2

// Author : Sri Harish

// If in the problem, the maze is given and certain cells are said to be restricted,
// then just mark those cells as '-1' and add a condition  in the Bounding Function

#include<iostream>
using namespace std;

void revert(int** maze,int r,int c) {   //Used double pointer(int**) to pass and access 2D arrays by
    for(int i=0;i<r;i++)                //using Dynamic Memory Allocation
        for(int j=0;j<c;j++)            //You can also use int* maze[] instead of int** maze
            maze[i][j]=0;               //Both are one and the same, just different representations
}                                       //Here we use '0' to show it's unvisited

void display(int* maze[],int r,int c) {
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++)
            cout<<maze[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int issafe(int* maze[],int row,int col,int r,int c) {   //Bounding Function
    if(row>=0 && col>=0 && row<r && col<c)              //Check if it's inside the Maze
        return 1;
    return 0;
}

void solve(int* maze[],int c_row,int c_col,int r, int c) {
    if(c_row==r-1 && c_col==c-1) {              //Reached end of the maze [r-1][c-1]
        display(maze,r,c);
    }
    int next_r = c_row;
    int next_c = c_col+1;                       //Moving to the immediate right cell
    if(issafe(maze,next_r,next_c,r,c)==1) {     //Checking if feasible
        maze[next_r][next_c]=1;
        solve(maze,next_r,next_c,r,c);          //Recursive call to move further this path
        maze[next_r][next_c]=0;                 //Once explored, we Backtrack to explore other paths
    }
    next_r = c_row+1;                           //Moving to the cell below
    next_c = c_col;
    if(issafe(maze,next_r,next_c,r,c)==1) {
        maze[next_r][next_c]=1;
        solve(maze,next_r,next_c,r,c);
        maze[next_r][next_c]=0;
    }
}


int main() {

    int r,c;
    cout<<"Enter no of rows and cols: ";
    cin>>r>>c;
    int *maze[r];                               //Dynamic Memory Allocation of 2D Array
    for(int i=0;i<r;i++)                        //Create a pointer array in the stack which act
        maze[i] = (int*)malloc(sizeof(int)*c);  //as row pointers and create columns in Heap memory
    revert(maze,r,c);                           //This way, u can access them just like a normal array
    maze[0][0]=1;           //Setting Initial position of Rat
    solve(maze,0,0,r,c);    //Letting the Rat loose
}


/*      PLAIN CODE

#include<iostream>
using namespace std;

void revert(int** maze,int r,int c) {
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            maze[i][j]=0;
}

void display(int* maze[],int r,int c) {
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++)
            cout<<maze[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int issafe(int* maze[],int row,int col,int r,int c) {
    if(row>=0 && col>=0 && row<r && col<c)
        return 1;
    return 0;
}

void solve(int* maze[],int c_row,int c_col,int r, int c) {
    if(c_row==r-1 && c_col==c-1) {
        display(maze,r,c);
    }
    int next_r = c_row;
    int next_c = c_col+1;
    if(issafe(maze,next_r,next_c,r,c)==1) {
        maze[next_r][next_c]=1;
        solve(maze,next_r,next_c,r,c);
        maze[next_r][next_c]=0;
    }
    next_r = c_row+1;
    next_c = c_col;
    if(issafe(maze,next_r,next_c,r,c)==1) {
        maze[next_r][next_c]=1;
        solve(maze,next_r,next_c,r,c);
        maze[next_r][next_c]=0;
    }
}


int main() {

    int r,c;
    cout<<"Enter no of rows and cols: ";
    cin>>r>>c;
    int *maze[r];
    for(int i=0;i<r;i++)
        maze[i] = (int*)malloc(sizeof(int)*c);
    revert(maze,r,c);
    maze[0][0]=1;
    solve(maze,0,0,r,c);
}
*/

// Author : Sri Harish
// https://github.com/sriharish252
// https://www.linkedin.com/in/sri-harish
