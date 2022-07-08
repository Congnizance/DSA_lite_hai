/* Problem Statement:
Write a C function to return minimum and maximum in an array. Your program should make the minimum number of comparisons.
*/

#include <stdio.h>
#include <stdlib.h>

/* function to print an array */
void print_array(int *arr, int n)
{
    int i=0;
    while(n-- != 0)
        printf("%d ",arr[i++]);
}

/* -------------function to find min and max elements in an array---------------*/

/* My approach:algo1 */
// Track the max and min element and swap if not
// Time complexity = O(n)
void max_min_arr(int arr[], int size, int *pmax, int *pmin)
{
    int i;
    for(i=1;i<size;i++)
    {
        // finds max
        if(*pmax < arr[i])
            *pmax = arr[i];
        // finds min
        if(*pmin > arr[i])
            *pmin = arr[i];
    }
}

/* main driver function */
int main()
{
    int arr[] = {13,5,17,11,5};
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
    int max=arr[0],min=arr[0];
    int* pmax=&max;
    int* pmin=&min;
    max_min_arr(arr, size, pmax, pmin);
    printf("\nMax: %d\n",*pmax);
    printf("Min: %d",*pmin);
    return 0;
}