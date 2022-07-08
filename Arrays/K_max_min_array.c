/* Problem Statement:
Given an array arr[] and an integer K where K is smaller than size of array, 
the task is to find the Kth smallest element in the given array. It is given 
that all array elements are distinct.
*/

#include <stdio.h>
#include <stdlib.h>

struct pair
{
    int kmin;
    int kmax;
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
// Algorithm: Sort in ascending order and print kth element from start and end
// for kthe min and max respectively
// Time complexity = O(n^2)
struct pair kmax_min_arr1(int arr[], int n, int k)
{
    struct pair kminmax;
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    kminmax.kmin = arr[k-1];
    kminmax.kmax = arr[n-k];
    return kminmax;
}

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
    struct pair kminmax = kmax_min_arr1(arr, size, k);
    printf("\nkMax: %d\n",kminmax.kmax);
    printf("kMin: %d",kminmax.kmin);
    return 0;
}