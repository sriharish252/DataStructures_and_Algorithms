// REVERSE A LINKED LIST
// Time Complexity : O(n)
// Space Complexity: O(1)

// Author : Sri Harish

//Iterative Method is used here to reverse the list
    //https://www.geeksforgeeks.org/reverse-a-linked-list/

// If u r coding in C, add #include<stdlib.h>
// To understand how to pass head pointer to functions refer :
    //https://www.geeksforgeeks.org/how-to-write-functions-that-modify-the-head-pointer-of-a-linked-list/


#include<iostream>
using namespace std;

struct node {                                       //Creation of the node structure of our Linked List
    int data;
    node* next;                                     //Pointer to hold the address of the next node
};

void push(node** head_ptr,int new_data) {           //STACK implementation is used here to insert elements, FIFO - First In Last Out
    node* new_node=(node*)malloc(sizeof(node));     //Creating a new space in the heap memory for our new node
    new_node->data=new_data;
    new_node->next=*head_ptr;                       //Adding our new node at the very beginning/front of the list
    *head_ptr=new_node;                             //Assigning our new node as the head of the list
}

void print_list(node* head) {
    node* temp=head;
    while(temp!=NULL) {                             //Traversing till the end of the list is reached
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void reverse_list(node** head_ptr) {                //Reversing the list using ITERATIVE method
    node* prev=NULL;                                //It is recommended to always initialize a pointer during declaration,
    node* curr=*head_ptr;                               //if u r unsure about the value, initialize it to NULL
    node* next=NULL;
    while(curr!=NULL) {
        next=curr->next;                            //Storing the next node, before breaking the link
        curr->next=prev;                            //Pointing the current node's next to the previous node
        prev=curr;                                  //Moving the prev pointer to current node for future use
        curr=next;                                  //Moving the curr pointer to next node
    }
    *head_ptr=prev;                                 //Assigning the end node as the Head
}                                                       //since in the reversed list, it'll be the Head

int main() {
    node* head=NULL;
    push(&head,40);                                 //Entering some sample inputs
    push(&head,30);
    push(&head,20);
    push(&head,10);
//    int n;                                        //If u wanna give the input manually
//    cout<<"Enter numbers to insert in the list (Enter \"NULL\" to stop) :\n";
//    while(cin>>n)
//        push(&head,n);
    cout<<"\nInitial \t: ";
    print_list(head);
    reverse_list(&head);
    cout<<"\nAfter Reversing : ";
    print_list(head);
}

// There is also a recursive method to implement this, but it is not covered here
    //since it doesn't offer any improvement in the time or space complexity


/*      PLAIN CODE

#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void push(node** head_ptr,int new_data) {
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=new_data;
    new_node->next=*head_ptr;
    *head_ptr=new_node;
}

void print_list(node* head) {
    node* temp=head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void reverse_list(node** head_ptr) {
    node* prev=NULL;
    node* curr=*head_ptr;
    node* next=NULL;
    while(curr!=NULL) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head_ptr=prev;
}

int main() {
    node* head=NULL;
    push(&head,40);
    push(&head,30);
    push(&head,20);
    push(&head,10);
//    int n;
//    cout<<"Enter numbers to insert in the list (Enter \"NULL\" to stop) :\n";
//    while(cin>>n)
//        push(&head,n);
    cout<<"Initial \t: ";
    print_list(head);
    reverse_list(&head);
    cout<<"\nAfter Reversing : ";
    print_list(head);
}
*/

// Author : Sri Harish
// https://github.com/sriharish252
// https://www.linkedin.com/in/sri-harish