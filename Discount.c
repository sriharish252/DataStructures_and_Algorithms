/*
An e-commerce company plans to give their customers a discount for the New Years holiday. 
The discount will be calculated on the basis of the bill amount of the order placed. The discount 
amount is the sum of all the odd digits ion the customer’s total bill amount. If no odd digit is present in the bill amount, 
then the discount will be zero.

Write an algorithm to find the discount for the given total bill amount.
*/
#include<stdio.h>
int discount(int num)
{
    int dcnt = 0;
    while(num!=0)
    {
        int rem = num%10;
        if((rem&1)==1)
            dcnt+=rem;
        num/=10;
    }
    return dcnt;
}
int main()
{
    int num;
    scanf("%d",&num);
    printf("%d",discount(num));
}