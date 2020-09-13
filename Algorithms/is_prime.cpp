// IS PRIME
// Check if a given number is prime or not
// Time Complexity : O(sqrt(n))

// Author : Sri Harish

// Check if the given number is divisible by any number from 2 till SquareRoot(given number)

#include<iostream>
#include<math.h>
using namespace std;

int isprime(int n) {
    int limit=sqrt(n);                  //Check till sqrt(given number)
    for(int i=2;i<=limit;i++)
        if(n%i==0)
            return 0;
    return 1;                           //No divisors were found, hence given number is prime
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
    int limit=sqrt(n);
    for(int i=2;i<=limit;i++)
        if(n%i==0)
            return 0;
    return 1;
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
*/

// Author : Sri Harish
// https://github.com/sriharish252
// https://www.linkedin.com/in/sri-harish