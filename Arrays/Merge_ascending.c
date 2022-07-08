/* Problem Statement:
Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in 
non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order 
without using any extra space.
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* -------------function to merge two arrays in ascending order---------------*/

/* My approach:algo1 */
// Algorithm: Merge by first element comparision
// Time complexity = O(n+m)
void merge(int a[], int b[], int na, int nb)
{
    int i,c=0,d=0;
    for(i=0;i<na+nb;i++)
    {
        if(a[c] <= b[d] && c < na)
        {
            printf("%d ",a[c]);
            c++;
        }
        else if(a[c] > b[d] && d < nb)
        {
            printf("%d ",b[d]);
            d++;
        }
        else if(d >= nb)
        {
            printf("%d ",a[c]);
            c++;
        }
        else
        {
            printf("%d ",b[d]);
            d++;
        }
    }
}

/* Algo2: compare and swap first elements then sort */
// Algorithm: Merge by first element comparision
// Time complexity = O((n+m)log(n+m))
void merge2(int a[], int b[], int na, int nb)
{
    int i;
    for(i=0;i<na;i++)
    {
        if(a[i] > b[0])
        {
            swap(&a[i], &b[0]);
            int firstele = b[0];
            int k;
            for(k=1;k<nb && b[k]<firstele;k++) 
            {
                b[k-1] = b[k];
            }
            b[k-1] = firstele;
        }
    }
    i=0;
    while(na-- != 0)
        printf("%d ",a[i++]);
    i=0;
    while(nb-- != 0)
        printf("%d ",b[i++]);
}

/* main driver function */
int main()
{
    int b[] = {5,11,13,15,17};
    int a[] = {1,3,5,7};
    /* take input from user */
    // int n;
    // printf("Enter size:\n");
    // scanf("%d",&n);
    // int arr[n];
    // printf("Enter array elements:\n");
    // for(int i=0;i<n;i++)
    //     scanf("%d",&arr[i]);
    int size_a = sizeof(a)/sizeof(a[0]);
    int size_b = sizeof(b)/sizeof(b[0]);
    print_array(a, size_a);
    print_array(b, size_b);
    merge2(a, b, size_a, size_b);
    return 0;
}