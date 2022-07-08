/* Problem Statement:
Write a C function to return minimum and maximum in an array. Your program should make the minimum number of comparisons.
*/

#include <stdio.h>
#include <stdlib.h>

struct pair
{
    int min;
    int max;
};

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
struct pair max_min_arr(int arr[], int size)
{
    int i;
    struct pair minmax;
    minmax.max = arr[0];
    minmax.min = arr[0];
    for(i=1;i<size;i++)
    {
        // finds max
        if(minmax.max < arr[i])
            minmax.max = arr[i];
        // finds min
        if(minmax.min > arr[i])
            minmax.min = arr[i];
    }
    return minmax;
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
    struct pair minmax = max_min_arr(arr, size);
    printf("\nMax: %d\n",minmax.max);
    printf("Min: %d",minmax.min);
    return 0;
}