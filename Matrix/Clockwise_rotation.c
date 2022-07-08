/* Problem Statement:
Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of 
the matrix.
*/

#include <stdio.h>
#include <stdlib.h>

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

/* utility function */
/* function to print an array */
void print_matrix(int r, int c, int matrix[][c])
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
}

/* Approach 1: Cyclic rotation at each iteration until 90` rotation */
// Time Complexity = O(r*c)
void clockwise_rotation(int r, int c, int matrix[][c])
{
    int i,j;
    int top=0;
    int down=r-1;
    int left=0;
    int right=c-1;

    int cycle;
    while(top <= down && left <= right)
    {
        for(cycle=0;cycle<(right-left);cycle++){
        int a = matrix[top][left];
        for(i=top;i<down;i++)
            matrix[i][left] = matrix[i+1][left];
        for(i=left;i<right;i++)
            matrix[down][i] = matrix[down][i+1];
        for(i=down;i>top;i--)
            matrix[i][right] = matrix[i-1][right];
        for(i=right;i>left+1;i--)
            matrix[top][i] = matrix[top][i-1];
        if(top != down && left != right)
            matrix[top][left+1] = a;
        }
        left++;
        down--;
        right--;
        top++;
    }
}

/* Approach 2: Printing observed pattern */
// Time Complexity = O(r*r)
void clockwise_rotation2(int r, int c, int matrix[][c])
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=r-1;j>=0;j--)
            printf("%d ",matrix[j][i]);
        printf("\n");
    }
}

/* main driver function */
int main()
{
    // int matrix[][2] = {{1,2},{3,4}};
    // int matrix[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // int matrix[][4] = {{1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}};
    int matrix[][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4},{5,5,5,5,5}};
    int c = sizeof(matrix[0])/sizeof(matrix[0][0]);
    int r = sizeof(matrix)/sizeof(matrix[0]);
    printf("Row: %d\n",r);
    printf("Column: %d\n",c);
    print_matrix(r,c,matrix);
    clockwise_rotation(r,c,matrix);
    printf("\n");
    print_matrix(r,c,matrix);
    printf("\n");
    clockwise_rotation2(r,c,matrix);
    // print_array(merge(matrix[0], matrix[1], 3, 3), 6);
}