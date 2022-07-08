/* Problem Statement:
Sudoku solver
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Global variable */
int n=9;

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

bool isSafe(int row, int col, int num, int board[][col])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(board[row][i] == num || board[i][col] == num)
            return false;
    }
    int startrow = row-row%3;
    int startcol = col-col%3;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i+startrow][j+startcol] == num)
                return false;
        }
    }
    return true;
}

bool sudokuSolver(int row, int col, int board[][col])
{
    if(row == n-1 && col == n)
        return true;
    if(col == n)
    {
        row++;
        col=0;
    }
    if(board[row][col]>0)
        return sudokuSolver(row,col+1,board);
    for(int num=1;num<10;num++)
    {
        if(isSafe(row, col, num, board))
        {
            board[row][col] = num;
            if(sudokuSolver(row, col+1, board))
                return true;
        }
        board[row][col] = 0;
    }
    return false;
}

/* main driver function */
int main()
{
    int board[9][9] = {{0,8,0,0,2,0,0,0,0},
                       {9,0,0,3,0,0,5,4,0},
                       {0,0,0,0,0,0,0,0,6},
                       {0,0,2,0,3,0,6,1,0},
                       {1,0,0,0,0,0,0,0,7},
                       {0,0,0,6,0,0,0,0,9},
                       {4,0,0,5,0,0,1,3,0},
                       {0,0,9,0,0,4,0,0,0},
                       {0,0,0,0,0,0,0,7,0}};
    sudokuSolver(9,9,board);
    print_matrix(9,9,board);
    return 0;
}