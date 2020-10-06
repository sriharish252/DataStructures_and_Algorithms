// Kadane's Algorithm
// Find the Sum of the Largest Contiguous Subarray 
// Time Complexity : O(n)

// Author : Sri Harish

// This is Dynamic Programming approach where the big problem is divided into parts and conquered
//  To understand this method better check these
//  https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
//  http://youtube.com/watch?v=86CQq3pKSUw

#include<iostream>
using namespace std;

long max_subarray_sum(long* ar,long n) {
	long sum=ar[0],max_sum=ar[0];		//Assigning the first element as the current sum and max_sum directly,
    for(int i=1;i<n;i++) {				 // since there is no previous larger value to compare with
	    if((sum+ar[i])>ar[i])			//Check if the current element is larger than the maximum subarray till this element
	        sum=sum+ar[i];				 // The largest of the two will be stored as current sum
	    else
	        sum=ar[i];
	    if(sum>max_sum)					//If the current sum is larger than the overall max_sum, assign max_sum as sum
	        max_sum=sum;				 // This max_sum is also called as global sum in many explanations
    }
	return max_sum;						//Returning the largest sum
}

int main() {
	long n;
	cin>>n;
	long ar[n];
	for(int i=0;i<n;i++)
	    cin>>ar[i];
    cout<<max_subarray_sum(ar,n);
}

// This is an efficient way of implementing Kadane's Algorithm
//  there are other ways of implementing it with O(n^2) time complexity


/*      PLAIN CODE

#include<iostream>
using namespace std;

int main() {
	long n;
	cin>>n;
	long ar[n];
	for(int i=0;i<n;i++)
	    cin>>ar[i];
	long sum=ar[0],max_sum=ar[0];
    for(int i=1;i<n;i++) {
	    if((sum+ar[i])>ar[i])
	        sum=sum+ar[i];
	    else
	        sum=ar[i];
	    if(sum>max_sum)
	        max_sum=sum;
    }
    cout<<max_sum;
}
*/

// Author : Sri Harish
// https://github.com/sriharish252
// https://www.linkedin.com/in/sri-harish