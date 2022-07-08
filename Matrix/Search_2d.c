/* Problem Statement:
Write an efficient algorithm that searches for a value target in an m x n integer matrix. 
This matrix has the following properties:
1) Integers in each row are sorted from left to right.
2) The first integer of each row is greater than the last integer of the previous row.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Approach 1: Taking advantage of sorted elements */
// Best case = O(r+c)
// Worst case = O(1)
bool searchMatrix(int r, int c, int matrix[][c], int target)
{
    int i=0,j=0;
    while(target >= matrix[i][0])
    {
        if(target == matrix[i][0])
            return true;
        i++;
    }
    i-=1;
    while(target >= matrix[i][j])
    {
        if(target == matrix[i][j])
            return true;
        j++;
    }
    return false;
}

/* main driver function */
int main()
{
    int matrix[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int c = sizeof(matrix[0])/sizeof(matrix[0][0]);
    int r = sizeof(matrix)/sizeof(matrix[0]);
    printf("Row: %d\n",r);
    printf("Column: %d\n",c);
    int k;
    printf("Enter target element:\n");
    scanf("%d",&k);
    if(searchMatrix(r,c,matrix,k))
        printf("FOUND");
    else
        printf("NOT FOUND");
}