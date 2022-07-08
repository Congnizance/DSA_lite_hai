/* Problem Statement:
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
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

/* -------------function to sort 0,1,2 element array---------------*/

/* My approach:algo1 */
// Algorithm: count the number of 0s, 1s and 2s then insert them in array in order.
// Time complexity = O(n) 
void sort012(int arr[], int n)
{
    int count0=0, count1=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i] == 0)
            count0++;
        else if(arr[i] == 1)
            count1++;
    }
    for(i=0;i<n;i++)
    {
        if(i < count0)
            arr[i] = 0;
        else if(i < count0+count1)
            arr[i] = 1;
        else
            arr[i] = 2;
    }
}

/* main driver function */
int main()
{
    int arr[] = {0,2,1,2,0};
    /* take input from user */
    // int n;
    // printf("Enter size:\n");
    // scanf("%d",&n);
    // int arr[n];
    // printf("Enter array elements:\n");
    // for(int i=0;i<n;i++)
    //     scanf("%d",&arr[i]);
    int size = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, size);
    sort012(arr, size);
    print_array(arr, size);
    return 0;
}