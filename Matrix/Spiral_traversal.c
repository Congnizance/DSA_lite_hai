/* Problem Statement:
Given a matrix of size r*c. Traverse the matrix in spiral form.
*/

#include <stdio.h>
#include <stdlib.h>

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

/* Approach 1: Using directions */
// Time Complexity = O(r*c)
void spirallyTraverse(int r, int c, int matrix[][c])
{
    int i;
    int top=0;
    int down=r-1;
    int left=0;
    int right=c-1;

    int direction=0;
    while(top <= down && left <= right)
    {
        if(direction == RIGHT)
        {
            for(i=left;i<=right;i++)
                printf("%d ",matrix[top][i]);
            top++;
        }
        else if(direction == DOWN)
        {
            for(i=top;i<=down;i++)
                printf("%d ",matrix[i][right]);
            right--;
        }
        else if(direction == LEFT)
        {
            for(i=right;i>=left;i--)
                printf("%d ",matrix[down][i]);
            down--;
        }
        else
        {
            for(i=down;i>=top;i--)
                printf("%d ",matrix[i][left]);
            left++;
        }
        direction = (direction+1)%4;
    }
}

/* Approach 2: Recursively decreasing the matrix dimensions and traversal */
void recur_spirallyTraverse(int i, int j, int r, int c, int matrix[r][c])
{
    if(i >= r && j >= c)
        return;
    int p;
    // printing first row
    for(p=j;p<c;p++)
        printf("%d ",matrix[i][p]);
    // printing last column
    for(p=i+1;p<r;p++)
        printf("%d ",matrix[p][c-1]);
    // printing last row if first row does not equal last row
    if(r-1 != i)
    {
        for(p=c-2;p>=j;p--)
            printf("%d ",matrix[r-1][p]);
    }
    // printing first column if last column does not equal first column
    if(c-1 != j)
    {
        for(p=r-2;p>=i;p--)
            printf("%d ",matrix[p][j]);
    }
    recur_spirallyTraverse(i+1,j+1,r-1,c-1,matrix);
}

/* main driver function */
int main()
{
    int matrix[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int c = sizeof(matrix[0])/sizeof(matrix[0][0]);
    int r = sizeof(matrix)/sizeof(matrix[0]);
    printf("Row: %d\n",r);
    printf("Column: %d\n",c);
    // spirallyTraverse(r, c, matrix);
    recur_spirallyTraverse(0,0,r,c,matrix);
}