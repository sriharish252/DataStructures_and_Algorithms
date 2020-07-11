// N QUEEN PROBLEM
// Find all possible solutions - enumeration problem
//Time Complexity : O(n^n)
//Recurrence Relation : T(n)=T(n-1)*n

#include<iostream>
using namespace std;

void revert_board(int board[],int n) {          //Resets the Boards by setting all values to -1
    for(int i=0;i<n;i++)
        board[i]=-1;
}

void display_board(int board[],int n) {         //Displays the Board
    for(int i=0;i<n;i++) {                      //In Board[] array, index specifies the column
        for(int j=0;j<n;j++) {                  //value specifies the row
            if(board[j]==i)
                cout<<"Q"<<i+1<<"  ";
            else
                cout<<" *  ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int issafe(int board[],int n,int count, int pos) {  //Checks if the specified Queen 'count' can be safely placed in 'pos' position
    if(board[pos]!=-1)      //if a Queen is already present in that position/column
        return 0;
    if(pos==0) {            //if the Queen is to be placed at the first column
        if(board[pos+1]==-1||(count-board[pos+1]>1)||(count-board[pos+1]<-1))   //Check immediate right col
            return 1;
    }
    else if(pos==n-1) {     //if the Queen is to be placed at the last column
        if(board[pos-1]==-1||(count-board[pos-1]>1)||(count-board[pos-1]<-1))   //Check immediate left col
            return 1;
    }                       //if the Queen is to be placed in middle column
    else if(board[pos-1]==-1 && board[pos+1]==-1)   //No Queen is present on immediate left & right cols
        return 1;
    else if(board[pos-1]==-1 && (count-board[pos+1]>1 || count-board[pos+1]<-1))    //No Queen is on left, Check right col
        return 1;
    else if(board[pos+1]==-1 && (count-board[pos-1]>1 || count-board[pos-1]<-1))    //No Queen is on right, Check left col
        return 1;
    else if((count-board[pos-1]>1 || count-board[pos-1]<-1)&&(count-board[pos+1]>1 || count-board[pos+1]<-1))
        return 1;                                                                   //Queens on both sides, check feasibility
    return 0;           //Nothing works, no feasible soln
}

int solve(int board[],int n,int count) {    //Main Recusive Func

    if(count==n)                            //All Queens are placed, so success
        return 1;

    for(int i=0;i<n;i++) {                  //Checks every column for Queen number in 'count'
        if(issafe(board,n,count,i)==1) {    //if safe to place in position i
            board[i]=count;                 //Place the Queen in the Board
            if(solve(board,n,count+1)==1)   //Check the next Queen placement, Recursion
                return 1;
            else                            //if the next Queen cannot be placed
                board[i]=-1;                //Backtrack and remove current Queen from the Board
        }
    }
    return 0;               //No Feasible solution
}


int main() {
    
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<endl;
    int board[n];
    revert_board(board,n);          //Setting the Board
    for(int i=0;i<n;i++) {          //Looping through all possibilities for the initial Queen
        board[i]=0;                 //Setting the first Queen
        if(solve(board,n,1)==1) {   //Func to place the subsequent Queens, returns 1 if feasible
            display_board(board,n); //Displaying feasible solutions
        }
        revert_board(board,n);      //Resetting the Board for next loop
    }
}
