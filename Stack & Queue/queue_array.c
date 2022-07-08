#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int front = -1;
int rear = -1;
int que[SIZE];

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

void display()
{
    int i;
    for(i=front;i<=rear;i++)
        printf("%d ",que[i]);
}

int main()
{
    enque(5);
    enque(6);
    enque(1);
    enque(3);
    deque();
    display();
    return 0;
}