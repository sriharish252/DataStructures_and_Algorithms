// PRIME NUMBERS - SIEVE OF ERATOSTHENES - O(n*log(log n))
// Find all the prime numbers till the given number 'n'
// Algorithm
// Time Complexity : O(n*log(log n))
// Recurrence Relation : T(n)=(n*(Harmonic Progression of primes till n))
//   https://www.geeksforgeeks.org/how-is-the-time-complexity-of-sieve-of-eratosthenes-is-nloglogn/
// Space Complexity : O(n)

//  Comparatively, for TIME efficiency Sieve of Eratosthenes is better than Sundaram
//  Comparatively, for SPACE efficiency Sieve of Sundaram is better than Eratosthenes

// Author : Sri Harish

// In a naive find all prime numbers, we select every number from '2' till 'n' and check if that no.
//  is not divisible by any value from '2' till 'n/2' (or till sqrt(n)), if not then it is prime

// In Sieve of Eratosthenes, we store all the values till 'n' in an array and select the values
//  from '2' till 'sqrt(n)' and then we eliminate the multiples of the selected no. in the array
//  This way, a lot of computing time is saved.


#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter the value of n (till which u want the prime numbers) : ";
    cin>>n;
//    n++;                      //Use this if u want to include the value 'n' too
    int sieve[n]={0};   //Value '0' states that the number is selected. Initially every number till 'n' is selected
    // sieve[] starts at index '0' but we know that prime number starts from 2, therefore we start selecting from 2
    
    for(int i=2;i<sqrt(n);i++) {        //Limit the selection till sqrt(n), coz of mathematics ;)
        if(sieve[i]==0) {   
            for(int j=i*i;j<n;j+=i) { //We start from i*i (i.e., i^2), coz if u analyse the working, every multiple of 'i'
//                                     // till i^2 will already be elminated when the primes before the selected 'i' are run
//                                   //We incrrement j by i, because we are eliminating multiples of i,
//                                      // so no need to loop through every element and check
                sieve[j]=1;         //Eliminating Non-primes. Value '1' in sieve[] represents that it's eliminated
            }
        }
    }
    for(int i=2;i<n;i++)
        if(sieve[i]==0)
            cout<<i<<" ";
    cout<<endl;
}

// There's a better version of Sieve of Eratosthenes with O(n) time complexity

// Can also be improved by creating a boolean sieve[] array instead of int sieve[],
//  since only '1' or '0' is stored in sieve[], we could use 'true' or 'false'


/*      PLAIN CODE

#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter the value of n (till which u want the prime numbers) : ";
    cin>>n;
//    n++;
    int sieve[n]={0};
    for(int i=2;i<sqrt(n);i++) {
        if(sieve[i]==0) {
            for(int j=i*i;j<n;j+=i) {
                sieve[j]=1;
            }
        }
    }
    for(int i=2;i<n;i++)
        if(sieve[i]==0)
            cout<<i<<" ";
    cout<<endl;
}
*/

// Author : Sri Harish
// https://github.com/sriharish252
// https://www.linkedin.com/in/sri-harish