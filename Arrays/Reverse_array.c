#include <stdio.h>
#include <stdlib.h>

/* function to print an array */
void print_array(int *arr, int n)
{
    int i=0;
    while(n-- != 0)
        printf("%d ",arr[i++]);
}

/* ------------function to reverse an array------------ */

/* Algo 1 */
// Direct assignment
// Time complexity = O(n)
int* reverse_array1(int *arr, int n)
{
    int i=0;
    int *rev = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        rev[i] = arr[n-i-1];
    return rev;
}

/* Algo 2 */
// Swapping start and end elements 
// Time complexity = O(n)
void reverse_array2(int *arr, int n)
{
    int temp=0;
    int start=0, end=n-1;
    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/* Algo 3 */
// Recursive swap
// Time complexity = O(n)
void reverse_array3(int *arr, int start, int end)
{
    int temp=0;
    if(start >= end)
        return;
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverse_array3(arr, start+1, end-1);
}

/* main driver function */
int main()
{
    int arr[] = {1,3,5,7,11};
    // sizeof(arr) = 20
    // sizeof(arr[0]) = 4
    int size = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, size);
    
    // algo 1
    int* rev = reverse_array1(arr, size);
    printf("\n");
    print_array(rev, size);
    
    // algo 2
    reverse_array2(arr, size);
    printf("\n");
    print_array(arr, size);
    
    // algo 3
    reverse_array3(arr, 0, size-1);
    printf("\n");
    print_array(arr, size);
    return 0;
}