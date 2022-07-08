#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

// stack variables
int stack1[SIZE];
int top1 = -1;
int stack2[SIZE];
int top2 = -1;

// inserts element in queue
void Enqueue(int x)
{
    if(isEmpty1())
        push1(x);
    else
    {
        while(!isEmpty1())
        {
            push2(pop1());
        }
        push1(x);
        while(!isEmpty2())
        {
            push1(pop2());
        }
    }
}

// deletes element from the queue
void Dequeue()
{
    pop1();
}

void push1(int x)
{
    stack1[++top1] = x;
}

int pop1()
{
    return stack1[top1--];
}

bool isEmpty1()
{
    if(top1 == -1)
        return true;
    else
        return false;
}

void push2(int x)
{
    stack2[++top2] = x;
}

int pop2()
{
    return stack2[top2--];
}

bool isEmpty2()
{
    if(top2 == -1)
        return true;
    else
        return false;
}

int main()
{
    Enqueue(5);
    Enqueue(6);
    Enqueue(1);
    Enqueue(3);
    Dequeue();
    return 0;
}