/* Problem Statement:
Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of 
the matrix.
*/

#include <stdio.h>
#include <stdlib.h>

/* utility function */
/* function to print an array */
void print_array(int *arr, int n)
{
    int i=0;
    while(n-- != 0)
        printf("%d ",arr[i++]);
    printf("\n");
}

/* Approach 1: Using directions */
// Time Complexity = O(r*c)
void median(int r, int c, int matrix[][c])
{
    int i;
}

/* main driver function */
int main()
{
    int matrix[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int c = sizeof(matrix[0])/sizeof(matrix[0][0]);
    int r = sizeof(matrix)/sizeof(matrix[0]);
    printf("Row: %d\n",r);
    printf("Column: %d\n",c);
    median(r,c,matrix);
    // print_array(merge(matrix[0], matrix[1], 3, 3), 6);
}