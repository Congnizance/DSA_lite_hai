/* Problem statement:
Find the number of paths in a matrix from top left corner to bottom right corner given only valid direction of
paths are right and down.
*/

#include <stdio.h>
#include <stdlib.h>

// Time complexity = O(2^(n+m))
int count_paths(int n, int m)
{
    if (n==1 || m == 1)
        return 1;
    return count_paths(n-1,m)+count_paths(n,m-1);
}

int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    printf("Paths: %d",count_paths(n,m));
}