// SUDOKO SOLVER
// Enumeration Problem
// Backtracking
// Time Complexity : O(9^n)
// Recurrence Relation : T(n) = T(n-1)*9 + 1
// Space Complexity : O(1)

// Author : Sri Harish

#include<iostream>
using namespace std;

void display(int* sudoku[]) {
    for(int i=0;i<9;i++,cout<<endl)
        for(int j=0;j<9;j++)
            cout<<sudoku[i][j]<<" ";
    cout<<endl;
}

int issafe(int* sudoku[],int row,int col,int digit) {
    
    for(int i=0;i<9;i++) {
        if(sudoku[row][i]==digit)       //Check the whole row
            return 0;
        if(sudoku[i][col]==digit)       //Check the whole column
            return 0;   
    }
    int sbgrd_r,sbgrd_c;                //Check the Subgrid (3x3 grid) for presence of same digit
    sbgrd_r = (row/3)*3;                //sbgrd_r (Subgrid_row) is the starting index of that subgrid
    sbgrd_c = (col/3)*3;                //For eg: 7/3 = 2.33 => 2; 2*3 = 6 => Subgrid starting index
    for(int i=sbgrd_r;i<sbgrd_r+3;i++)
        for(int j=sbgrd_c;j<sbgrd_c+3;j++)
            if(sudoku[i][j]==digit)
                return 0;
    return 1;
}

void solve(int* sudoku[],int row,int col) {
    if(row==8 && col==9)            //Crossed the End, i.e., Traversed the whole matrix
        display(sudoku);
    else {
        if(col>8) {                 //Column limit reached, move to next row
            col=0;
            row=row+1;
        }
        if(sudoku[row][col]==0) {                   //If cell is empty
            for(int i=1;i<=9;i++)                   //Check every digit from 1 to 9
                if(issafe(sudoku,row,col,i)==1) {
                    sudoku[row][col]=i;
                    solve(sudoku,row,col+1);        //Move to the next cell, row-by-row
                    sudoku[row][col]=0;             //Backtracking
                }
        }
        else
            solve(sudoku,row,col+1);
    }
}

int main() {
    int *sudoku[9];
    for(int i=0;i<9;i++)
        sudoku[i]=(int*)calloc(9,sizeof(int));  //All values are initialized with 0, because of calloc()
    int n;
    cout<<"Enter the number of entries already available in the Sudoku : ";
    cin>>n;
    cout<<"Enter the row, col and the value of the cell :\n";
    int row,col,value;
    for(int i=0;i<n;i++) {
        cin>>row>>col>>value;
        sudoku[row][col]=value;
    }
    solve(sudoku,0,0);
}


/*      PLAIN CODE

#include<iostream>
using namespace std;

void display(int* sudoku[]) {
    for(int i=0;i<9;i++,cout<<endl)
        for(int j=0;j<9;j++)
            cout<<sudoku[i][j]<<" ";
    cout<<endl;
}

int issafe(int* sudoku[],int row,int col,int digit) {
    
    for(int i=0;i<9;i++) {
        if(sudoku[row][i]==digit)
            return 0;
        if(sudoku[i][col]==digit)
            return 0;
    }
    int sbgrd_r,sbgrd_c;
    sbgrd_r = (row/3)*3;
    sbgrd_c = (col/3)*3;
    for(int i=sbgrd_r;i<sbgrd_r+3;i++)
        for(int j=sbgrd_c;j<sbgrd_c+3;j++)
            if(sudoku[i][j]==digit)
                return 0;
    return 1;
}

void solve(int* sudoku[],int row,int col) {
    if(row==8 && col==9)
        display(sudoku);
    else {
        if(col>8) {
            col=0;
            row=row+1;
        }
        if(sudoku[row][col]==0) {
            for(int i=1;i<=9;i++)
                if(issafe(sudoku,row,col,i)==1) {
                    sudoku[row][col]=i;
                    solve(sudoku,row,col+1);
                    sudoku[row][col]=0;
                }
        }
        else
            solve(sudoku,row,col+1);
    }
}

int main() {
    int *sudoku[9];
    for(int i=0;i<9;i++)
        sudoku[i]=(int*)calloc(9,sizeof(int));
    int n;
    cout<<"Enter the number of entries already available in the Sudoku : ";
    cin>>n;
    cout<<"Enter the row, col and the value of the cell :\n";
    int row,col,value;
    for(int i=0;i<n;i++) {
        cin>>row>>col>>value;
        sudoku[row][col]=value;
    }
    solve(sudoku,0,0);
}
*/

// Author : Sri Harish
// https://github.com/sriharish252
// https://www.linkedin.com/in/sri-harish
