#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int ele)
{
    top += 1;
    stack[top] = ele;
}

int pop()
{
    int item;
    item = stack[top];
    top -= 1;
    return item;
}

int main()
{
    push(2);
    push(3);
    printf("%d ",pop());
    printf("%d ",pop());
    return 0;
}