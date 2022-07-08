/* Problem Statement:
Given an array arr[] denoting heights of N towers and a positive integer K, you 
have to modify the height of each tower either by increasing or decreasing them 
by K only once. After modifying, height should be a non-negative integer. 
Find out the minimum possible difference of the height of shortest and longest 
towers after you have modified each tower.
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

/* -------------function to minimize heights---------------*/

/* My approach:algo1 */
// Algorithm:
// Time complexity = O()

/* main driver function */
int main()
{
    int arr[] = {13,5,17,11,15};
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
    return 0;
}