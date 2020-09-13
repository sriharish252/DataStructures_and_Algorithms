// IS PRIME - Efficient Approach 
// Check if a given number is prime or not
// Time Complexity : O(n*log(n))

// Author : Sri Harish

// Every prime number, except 2 and 3, is in the format 6*k-1 and 6*k+1
// Hence we check if the given is not divisible by every prime number till SquareRoot(given number)

//This is more efficient since we are not checking divisibility with every single number till Sqrt(n)

#include<iostream>
#include<math.h>
using namespace std;

int isprime(int n) {                        //Very efficient method
    if(n<=1)
        return 0;
    if(n==2 || n==3)
        return 1;
    if(n%2==0 || n%3==0)
        return 0;
    
    int k=1;
    int limit=sqrt(n);
    int left  = 6*k-1;   //5                //Most Prime numbers (excluding 2 and 3) follow this pattern => 6*k-1 OR 6*k+1
    int right = 6*k+1;   //7                //Hence we reduce the number of elements needed to check if a number is prime
    while(left<=limit) {
        if((n%left==0) || (n%right==0))     //Check if the given number is divisible by the selected numbers
            return 0;
        k++;
        left = 6*k-1;                       //Updating the next numbers used to check
        right= 6*k+1;
    }
    return 1;                               //No divisors were found, hence given number is prime
}

int main() {

    int n;
    cout<<"Enter n: ";
    cin>>n;
    if(isprime(n))
        cout<<"Prime";
    else
        cout<<"Not Prime";
}


/*      PLAIN CODE

#include<iostream>
#include<math.h>
using namespace std;

int isprime(int n) {
    if(n<=1)
        return 0;
    if(n==2 || n==3)
        return 1;
    if(n%2==0 || n%3==0)
        return 0;
    
    int k=1;
    int limit=sqrt(n);
    int left  = 6*k-1;
    int right = 6*k+1;
    while(left<=limit) {
        if((n%left==0) || (n%right==0))
            return 0;
        k++;
        left = 6*k-1;
        right= 6*k+1;
    }
    return 1;
}

int main() {

    int n;
    cin>>n;
    if(isprime(n))
        cout<<"Prime";
    else
        cout<<"Not Prime";
}

*/

// Author : Sri Harish
// https://github.com/sriharish252
// https://www.linkedin.com/in/sri-harish