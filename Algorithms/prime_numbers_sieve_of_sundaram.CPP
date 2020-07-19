// PRIME NUMBERS - SIEVE OF SUNDARAM
// Find all the prime numbers till the given number 'n'
// Algorithm
// Time Complexity : O(n*log n)
// Recurrence Relation : T(n)=(n*(Harmonic Progression of 2^i till n))
// Space Complexity : O(n)
//  O(n) states that it's a linear space complexity
//  but it actually uses only (n-1)/2 blocks in sieve[] instead of 'n' blocks

//  Comparatively, for TIME efficiency Sieve of Eratosthenes is better than Sundaram
//  Comparatively, for SPACE efficiency Sieve of Sundaram is better than Eratosthenes

// Author : Sri Harish

// We store all the values till 'm' (m=(n-1)/2) in sieve[] array
// We loop from i=1 and j=1, calculate z=i+j+2*i*j for every i and j value
//  till (z>m && i==j), if calculated 'z' is valid, eliminate that value from sieve[]
// Constraints:
//      j>=i and i,j>0
//      z<=m
// Prime Nos = i*2+1 for every selected(or uneliminated) value in sieve[i]

// Sieve of Sundaram doesn't give the prime no '2', so '2' must be printed manually


#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the value of n (till which u want the prime numbers) : ";
    cin>>n;
    int m=(n-1)/2;
//    m++;                      //Use this if u want to include the value 'n' too
    int sieve[m] = {0};         // '0' represents selected, initially every value is selected
    int i=1,j=1,z;              //i=1,j=1 initially
    while(1) {
        z=i+j+2*i*j;            //'z' represents the no. to be eliminated
        if(i==j && z>m)         //Check if 'z' is out of bounds and no more 'z' value is possible
            break;
        if(z<=m) {              //Check if 'z' is within bounds
            sieve[z]=1;           //Eliminate 'z' from sieve[] by assigning '1'
            j++;                  //For next 'z' calculation
        }
        else {
            i++;                //If 'z' is out of bounds, increment 'i' and reset 'j' to 'i'
            j=i;
        }
    }
    cout<<"2 ";                 //Since Sieve of Sundaram doesn't give '2' as a prime, it starts from 3
    for(int i=1;i<m;i++) {      // because we do i*2+1, therefore min value possible is 1*2+1 => 3
        if(sieve[i]==0)
            cout<<i*2+1<<" ";   //Printing primes from '3'
    }

cout<<endl;
}

// We can also use bool sieve[] instead of int sieve[] for better computation


/*      PLAIN CODE

#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the value of n (till which u want the prime numbers) : ";
    cin>>n;
    int m=(n-1)/2;
//    m++;
    int sieve[m] = {0};
    int i=1,j=1,z;
    while(1) {
        z=i+j+2*i*j;
        if(i==j && z>m)
            break;
        if(z<=m) {
            sieve[z]=1;
            j++;
        }
        else {
            i++;
            j=i;
        }
    }
    cout<<"2 ";
    for(int i=1;i<m;i++) {
        if(sieve[i]==0)
            cout<<i*2+1<<" ";
    }

cout<<endl;
}
*/

// Author : Sri Harish
// https://github.com/sriharish252
// https://www.linkedin.com/in/sri-harish