// PRIME NUMBERS - MODIFIED SIEVE OF ERATOSTHENES - O(n)
// Find all the prime numbers till the given number 'n'
// Algorithm
// Time Complexity : O(n)
// Recurrence Relation : Since every element that is to be eliminated is visited only once, it has linear time complexity

// Author : Sri Harish

// This is a modified version of Sieve of Eratosthenes for better time complexity
// This is done by making conditions in a way that an eliminated element is not revisited again to be eliminated again

// We use three arrays: isprime[], spf[] and prime[]
//      isprime[] tells if a number is prime or not, it keeps track of all the eliminated nos
//      spf[] tells the Smallest Prime Factor of a number, this is used to not re-eliminate an eliminated no
//      prime[] stores all the found prime nos
// Initially the values '0' and '1' are set as not primes in the isprime[] array
// Loop 'i' from starting '0' to ending 'n' of isprime[]
//      If the index i in isprime is set as 'not eliminated'
//          Update the value 'i' in prime[]
//          Update spf[i] with the prime no 'i'
//      Loop through prime[] till the last found prime no
//          Check if(( i*current_prime_no < n ) and ( current_prime_no <= spf[i] ))     //These conditions make sure that an eliminated value isn't visited again
//              Then eliminate i*current_prime_no in isprime[]
//              And set spf[i*current_prime_no] = current_prime_no
// All the uneliminated values in isprime and the all the values in prime[] are the prime nos till 'n'


#include<iostream>
using namespace std;

struct node {       //Linked List reepresenting prime[] array
    int data;
    node* next;
};

int main() {
    int n;
    cout<<"Enter the value of n (till which u want the prime numbers) : ";
    cin>>n;
//    n++;                      //Use this if u want to include the 'n' value too
    int isprime[n]={0};         //Here '0' represents it's selected, initially every element is considered as prime
    int spf[n]={0};             //Initially every element is assigned with '0', meaning it's unassigned
    
    isprime[0]=isprime[1]=1;    //We know 0 and 1 are not prime, so manually assigning their isprime[] to '1'
    
    node *start,*last,*temp;           //initial starting node and ending node pointers of prime[]

    for(int i=2;i<n;i++) {
        if(isprime[i]==0) {
            temp=(node*)malloc(sizeof(node));     //Creating a new node for the selected prime no 'i'
            if(i==2) {                  //If this is the very first node created
                start=temp;             //This will be the starting node of the list
                last=temp;              //And this will also be the last node of the list
            }
            else {
                last->next=temp;
                last=temp;
            }
            last->data=i;               //Inserting the new data into prime[]
            last->next=NULL;            //There is no node next to the new one
            spf[i]=i;
        }
        temp=start;
        while((temp != NULL) && (temp->data <= spf[i]) && (i*temp->data < n)) { //Conditions to prevent revisiting an eliminated value
            isprime[i*temp->data] = 1;          //Eliminating the value i*temp->data
            spf[i*temp->data] = temp->data;     //Updating spf[]
            temp = temp->next;                  //Traversing to the next node in prime[]
        }
    }

    for(int i=0;i<n;i++)                        //Printing all primes
        if(isprime[i]==0)
            cout<<i<<" ";

cout<<endl;
}


/*      PLAIN CODE

#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

int main() {
    int n;
    cout<<"Enter the value of n (till which u want the prime numbers) : ";
    cin>>n;
//    n++;
    int isprime[n]={0};
    int spf[n]={0};
    isprime[0]=isprime[1]=1;
    node *start,*last,*temp;

    for(int i=2;i<n;i++) {
        if(isprime[i]==0) {
            temp=(node*)malloc(sizeof(node));
            if(i==2) {
                start=temp;
                last=temp;
            }
            else {
                last->next=temp;
                last=temp;
            }
            last->data=i;
            last->next=NULL;
            spf[i]=i;
        }
        temp=start;
        while((temp != NULL) && (temp->data <= spf[i]) && (i*temp->data < n)) {
            isprime[i*temp->data] = 1;
            spf[i*temp->data] = temp->data;
            temp = temp->next;
        }
    }
    for(int i=0;i<n;i++)
        if(isprime[i]==0)
            cout<<i<<" ";
}
*/

// Author : Sri Harish
// https://github.com/sriharish252
// https://www.linkedin.com/in/sri-harish