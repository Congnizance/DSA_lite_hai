/* Problem Statement:
Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) 
which has the maximum sum and return its sum.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* function to print an array */
void print_array(int *arr, int n)
{
    int i=0;
    while(n-- != 0)
        printf("%d ",arr[i++]);
    printf("\n");
}

/* Utility function */
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

/* -------------function to find maximum sum of contiguous sub-array---------------*/

/* My approach:algo1 */
// Algorithm:
// Time complexity = O(undefined)
// wrong solution
void subsum(int arr[], int n)
{
    int start=0,end=n-1,i, sum=0;
    for(i=start;i<=end;i++)
        sum+=arr[i];
    int k=0;
    while(1)
    {
        if(sum-arr[start]>sum)
        {
            sum = sum-arr[start];
            start++;
            k++;
        }
        if(sum-arr[end]>sum)
        {   
            sum = sum-arr[end]; 
            end--;
            k++;
        }
        if(k==0)
            break;
        k=0;
    }
    for(i=start;i<=end;i++)
        printf("%d ",arr[i]);
}

/* Kadane's alogrithm */
// Time complexity = O(n)
int subsum2(int arr[], int n)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    int i,start=0,end=0,s=0;
    for(i=0;i<n;i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if(max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if(max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i+1;
        }
    }
    for(i=start;i<=end;i++)
        printf("%d ",arr[i]);
    return max_so_far;
}

/* Another solution */
int subsum3(int arr[], int n)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i] <= max_ending_here+arr[i])
            max_ending_here+=arr[i];
        else
            max_ending_here = arr[i];
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

/* Dyanamic Programming solution */
int subsum4(int arr[], int n)
{
    int max_so_far = arr[0];
    int curr_max = arr[0];
    int i;
    for(i=0;i<n;i++)
    {
        curr_max = max(arr[i], curr_max+arr[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

/* main driver function */
int main()
{
    int arr[] = {-2,-1,-3,-2,-5};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, size);
    // subsum(arr, size);
    printf("\n%d",subsum2(arr, size));
    // printf("%d",subsum3(arr, size));
    // printf("%d",subsum4(arr, size));
    return 0;
}   