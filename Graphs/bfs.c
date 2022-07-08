#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int front = -1;
int rear = -1;
int que[100];

void enque(int x)
{
    if(front == -1 && rear == -1)
    {
        ++front;
        ++rear;
        que[rear] = x;
    }
    else
    {
        ++rear;
        que[rear] = x;
    }
}

int deque()
{
    return que[front++];
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

void BFS(int root, int v, int matrix[][v], bool visited[])
{
    enque(root);
    visited[root] = true;
    while(front <= rear)
    {
        root = que[front];
        for(int i=0;i<v;i++)
        {
            if(matrix[root][i] != 0 && !visited[i])
            {
                enque(i);
                visited[i] = true;
            }
        }
        printf("%d ",deque());
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
    printf("\n");
    for(int i=0;i<v;i++)
        if(!visited[i]){
            BFS(i,v,matrix,visited);
            printf("\n");
        }
    return 0;
}
