/* Problem Statement:
Locate the position of n queens if possible in a nxn chessboard such that these n queens do not kill each other.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Global variable */
int n;

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

void fill(int r, int c, int matrix[r][c])
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            matrix[i][j] = 0;
    }
}

bool isSafe(int row, int col, int board[n][n])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(board[row][i] == 1 || board[i][col] == 1)
            return false;
    }
    i=1;
    while(row+i < n && col+i < n)
    {
        if(board[row+i][col+i] == 1)
            return false;
        i++;
    }
    i=1;
    while(row-i >= 0 && col+i < n)
    {
        if(board[row-i][col+i] == 1)
            return false;
        i++;
    }
    i=1;
    while(row+i < n && col-i >=0)
    {
        if(board[row+i][col-i] == 1)
            return false;
        i++;
    }
    i=1;
    while(row-i >= 0 && col-i >= 0)
    {
        if(board[row-i][col-i] == 1)
            return false;
        i++;
    }
    return true;
}

bool nqueens(int row, int board[n][n])
{
    if(row == n)
        return true;
    for(int col=0;col<n;col++)
    {
        if(isSafe(row, col, board))
        {
            board[row][col] = 1;
            if(nqueens(row+1, board))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

/* main driver function */
int main()
{
    /* number of queens */
    n=5;
    int board[n][n];
    /* fills the entire board with 0 to represent no queen placed */
    fill(n, n, board);
    nqueens(0,board);
    print_matrix(n,n,board);
    return 0;
}