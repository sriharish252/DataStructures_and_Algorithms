// KNIGHT'S TOUR Problem
// Find all possible solutions - Enumeration Problem
// Backtracking
// Time Complexity : O(8^n)
// Recurrence Relation : T(n) = T(n-1)*8 (worst case)
// Time Complexity Analysis : http://techieme.in/solving-the-knights-tour-problem/


#include<iostream>
using namespace std;

#define n 5                     //We define 'n' instead of getting it as input because
int board[n][n];                //it's troublesome to send 2D arrays as functions with a variable 'n'
int row_pos[]={-2,-2,-1,-1,1, 1,2, 2};  //All possible movements of a Knight from a given position
int col_pos[]={-1, 1,-2, 2,2,-2,1,-1};  //For instance: [c_row-2,c_col-1] is one movement

void revert() {                 //Resets the Board
    for(int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            board[i][j]=-1;
}

void display() {                //Displays the Board
    for(int i=0;i<n;i++) {
        for (int j=0;j<n;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int issafe(int c_row,int c_col) {       //Bounding Function
    if(c_row>=0 && c_row<n && c_col>=0 && c_col<n && board[c_row][c_col]==-1)
        return 1;
    return 0;
}

//c_row - Current Row
//move - Move Number
int solve(int c_row,int c_col,int move) {   //Recursion Function, loops through every possible movement
    if(move == n*n)         	//if move reached to n^2 then every cell is visited
        return 1;
    for(int i=0;i<8;i++) {          //loops for every possible move
        int x = c_row+row_pos[i];   //row of next possible position
        int y = c_col+col_pos[i];
        if(issafe(x,y)==1) {        //Check if safe
            board[x][y]=move;
            if(solve(x,y,move+1)==1)    //Proceed to next move
                return 1;
            else
                board[x][y]=-1;     //Backtracking - if the subsequent moves failed
        }
    }
    return 0;
}

int main() {
    revert();                       //Reset board
    for(int i=0;i<n;i++)            //Loop to start at every position in the board
        for(int j=0;j<n;j++) {
            board[i][j]=0;          //Fix starting position
            if(solve(i,j,1)==1)     //Solve for the subsequent moves
                display();
            revert();               //Reset board for next starting point
        }
}
