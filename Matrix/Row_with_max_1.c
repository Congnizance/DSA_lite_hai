/* Problem Statement:
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index 
of the first row that has the maximum number of 1's.
*/

#include <stdio.h>
#include <stdlib.h>

/* Approach 1: Using directions */
// Time Complexity = O(r*c)
int rowWithMax1(int r, int c, int matrix[][c])
{
    int i, j, max=-1, index=0;
    for(i=0;i<r;i++)
    {
        int count=0;
        for(j=0;j<c;j++)
        {
            if(matrix[i][j] == 1)
                count++;
            else if(matrix[i][j] > 1)
                break;
        }
        if(max < count)
        {
            max=count;
            index=i;
        }
    }
    return index;
}

/* main driver function */
int main()
{
    int matrix[][3] = {{0,1,1},{1,1,2},{0,0,0}};
    int c = sizeof(matrix[0])/sizeof(matrix[0][0]);
    int r = sizeof(matrix)/sizeof(matrix[0]);
    printf("Row: %d\n",r);
    printf("Column: %d\n",c);
    printf("%d",rowWithMax1(r,c,matrix));
}