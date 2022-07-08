/* Problem Stament:
Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) 
over all choices of indexes such that both c > a and d > b.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* function to find pair with max value */
// Time Complexity = O(n^4)
int maxValue(int c, int matrix[][c])
{
    int maxValue = INT_MIN;
    int i,j,k,l;
    for(i=0;i<c;i++)
    {
        for(j=0;j<c;j++)
        {
            for(k=i+1;k<c;k++)
            {
                for(l=j+1;l<c;l++)
                {
                    if(matrix[k][l] - matrix[i][j] > maxValue)
                        maxValue = matrix[k][l] - matrix[i][j];
                }
            }
        }
    }
    return maxValue;
}

/* main driver function */
int main()
{
    int matrix[5][5] = {{1, 2, -1, -4, -20 },{-8, -3, 4, 2, 1 },{3, 8, 6, 1, 3 },{-4, -1, 1, 7, -6 },{0, -4, 10, -5, 1 }};
    printf("Max Pair: %d",maxValue(5, matrix));
}