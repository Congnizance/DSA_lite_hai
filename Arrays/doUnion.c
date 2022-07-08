/* Problem Statement:
Given two arrays a[] and b[] of size n and m respectively. The task is to find union 
between these two arrays.
Union of the two arrays can be defined as the set containing distinct elements from 
both the arrays. If there are repetitions, then only one occurrence of element should 
be printed in the union.
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

/* -------------function to join two arrays---------------*/

/* My approach:algo1 */
// Algorithm: Compare and insert
// Time complexity = O(n*m)
int* merge(int a[], int b[], int na, int nb, int* size_c)
{
    int i;
    int *c = (int*)malloc((na+nb)*sizeof(int));
    for(i=0;i<na;i++)
        c[i] = a[i];
    int d = na;
    for(i=0;i<nb;i++)
    {
        int k=0;
        for(int j=0;j<na;j++)
        {
            if(b[i] == c[j])
                k=1;
        }
        if(k == 0)
            c[d++] = b[i];
    }
    *size_c = d;
    return c;
}

/* main driver function */
int main()
{
    int a[] = {13,5,17,11,19};
    int b[] = {2,3,5,7,11,13};
    int size_a = sizeof(a)/sizeof(a[0]);
    int size_b = sizeof(b)/sizeof(b[0]);
    print_array(a, size_a);
    print_array(b, size_b);
    int size_c = 0;
    int *c = merge(a, b, size_a, size_b, &size_c);
    print_array(c, size_c);
    return 0;
}