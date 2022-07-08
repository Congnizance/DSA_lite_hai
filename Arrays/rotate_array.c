/* Problem Statement:
Given an array, rotate the array by k position in clock-wise direction.
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

/* -------------function to rotate an array---------------*/

/* My approach:algo1 */
// Algorithm: Shift all indexes by k position to right and assign the last indexes in beginning.
// Time complexity = O(n)
void rotate(int arr[], int n)
{
    int i, temp=arr[n-1]; 
    for(i=n-2;i>=0;i--)
        arr[i+1] = arr[i];
    arr[0] = temp;
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
    while(k!=0)
    {
        rotate(arr, size);
        k--;
    }
    print_array(arr, size);
    return 0;
}