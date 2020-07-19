// NON-CONTIGUOUS SUBSET SUM Problem
// Find all subsets in a given set 'set[]' whose sum is equal to the expected sum 'k'
// Enumeration Problem - Hence we use Backtracking
// If it was an Optimization Problem, Dynamic Programming is the best approach
// Time Complexity : O(2^n)
// Recurrence Relation : T(n) = 2*T(n-1)
// If done in Dynamic Programming, Time Complexity : O(n^2) , Therefore more efficient than this

// Author : Sri Harish

// We take 2 values 'actual' -> actual sum and 'rem' -> remaining sum
// actual gives the sum of the selected elements
// rem gives the sum of the remaining elements towards the right in the set
// We keep track of the selected elements by using the selected[] array
// Initially, actual = 0 and rem = sum of the set


#include<iostream>
using namespace std;

void display(int* set,int* selected,int n) {
    cout<<"[ ";
    for(int i=0;i<n;i++)
        if(selected[i]==1)
            cout<<set[i]<<" ";
    cout<<"]"<<endl;
}

int issafe(int k,int actual,int rem) {		//Feasibility Check
    if(actual<=k && rem>=0)
        return 1;
    return 0;
}

void solve(int set[],int selected[],int n,int k,int pos,int actual,int rem) {
    if(actual==k) {                                 //Check if we found our expected sum
        display(set,selected,n);
    }
    else if(issafe(k,actual,rem)==1) {        //Check if this pos is safe
        selected[pos]=1;                            //Select the position
        solve(set,selected,n,k,pos+1,actual+set[pos],rem-set[pos]); //Explore path with this pos selected
        selected[pos]=0;                            //Deselect this position
        solve(set,selected,n,k,pos+1,actual,rem-set[pos]);    //Explore path with the pos unselected
    }
}

int main() {
    int n;
    cout<<"Enter size of set: ";
    cin>>n;
    int set[n],k;
    int selected[n]={0};              //initializes all values in the array to '0'
    int sum=0;
    cout<<"Enter the elements of set: ";
    for(int i=0;i<n;i++) {
        cin>>set[i];
        sum+=set[i];
    }
    cout<<"Enter the expected sum: ";
    cin>>k;
    solve(set,selected,n,k,0,0,sum);
}


/*      PLAIN CODE

#include<iostream>
using namespace std;

void display(int* set,int* selected,int n) {
    cout<<"[ ";
    for(int i=0;i<n;i++)
        if(selected[i]==1)
            cout<<set[i]<<" ";
    cout<<"]"<<endl;
}

int issafe(int k,int actual,int rem) {
    if(actual<=k && rem>=0)
        return 1;
    return 0;
}

void solve(int set[],int selected[],int n,int k,int pos,int actual,int rem) {
    if(actual==k) {
        display(set,selected,n);
    }
    else if(issafe(k,actual,rem)==1) {
        selected[pos]=1;
        solve(set,selected,n,k,pos+1,actual+set[pos],rem-set[pos]);
        selected[pos]=0;
        solve(set,selected,n,k,pos+1,actual,rem-set[pos]);
    }
}

int main() {
    int n;
    cout<<"Enter size of set: ";
    cin>>n;
    int set[n],k;
    int selected[n]={0};
    int sum=0;
    cout<<"Enter the elements of set: ";
    for(int i=0;i<n;i++) {
        cin>>set[i];
        sum+=set[i];
    }
    cout<<"Enter the expected sum: ";
    cin>>k;
    solve(set,selected,n,k,0,0,sum);
}
*/

// Author : Sri Harish
// https://github.com/sriharish252
// https://www.linkedin.com/in/sri-harish
