#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 100

int stack[size];
int top = -1;

void push(int ele)
{
    top += 1;
    stack[top] = ele;
}

void pop()
{
    top -= 1;
}

void print_matrix(int c, int matrix[][c])
{
    int i,j;
    for(i=0;i<c;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
}

void addEdgeM(int i, int j, int v, int matrix[][v])
{
    matrix[i][j] = 1;
}

void DFS(int root, int v, int matrix[][v], bool visited[])
{
    push(root);
    while(top != -1)
    {
        root = stack[top];
        pop();
        if(!visited[root])
        {
            printf("%d ",root);
            visited[root] = true;
        }
        // nodes are given priority based on ascending order
        for(int i=v-1;i>=0;i--)
            if(matrix[root][i] != 0 && !visited[i])
                push(i);
    }
}

int main()
{
    int v;
    printf("Enter number of edges: ");
    scanf("%d",&v);
    int matrix[v][v];
    // intialize matrix to 0 representing no edges
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            matrix[i][j] = 0;
    
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    
    // add edges
    addEdgeM(0,1,v,matrix);
    addEdgeM(0,2,v,matrix);
    addEdgeM(1,2,v,matrix);
    addEdgeM(2,0,v,matrix);
    addEdgeM(2,3,v,matrix);
    addEdgeM(3,3,v,matrix);
    print_matrix(v,matrix);
    // DFS(2,v,matrix,visited);
    printf("\n");
    for(int i=0;i<v;i++)
        if(!visited[i]){
            DFS(i,v,matrix,visited);
            printf("\n");
        }
    return 0;   
}