/* Problem Statement:
Given an array of N integers, and an integer K, find the number of pairs of elements in 
the array whose sum is equal to K.
*/

#include <stdio.h>
#include <stdlib.h>

/* function to print an array */
void print_array(int *arr, int n)
{
    int i=0;
    while(n-- != 0)
        printf("%d ",arr[i++]);
    printf("\n");
}

/* -------------function to count the pair with given sum of an array---------------*/

/* My approach:algo1 */
// Algorithm: Brute Force
// Time complexity = O(n^2)
int count_pair(int arr[], int n, int k)
{
    int i,j, count=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j] == k)
                count++;
        }
    }
    return count;
}

/* main driver function */
int main()
{
    int arr[] = {13,5,17,11,15,1,2,3,4,10};
    /* take input from user */
    // int n;
    // printf("Enter size:\n");
    // scanf("%d",&n);
    // int arr[n];
    // printf("Enter array elements:\n");
    // for(int i=0;i<n;i++)
    //     scanf("%d",&arr[i]);
    int k;
    scanf("%d",&k);
    int size = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, size);
    printf("%d",count_pair(arr, size, k));
    return 0;
}