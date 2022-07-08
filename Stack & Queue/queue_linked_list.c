#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;

// Allocates memory for a new node
Node* newNode(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// adds a new element at the end of queue
void enque(Node** front, Node** rear, int item)
{
    Node* temp;
    temp = newNode(item);
    // if queue is empty
    if (*front == NULL)
        *front = temp;
    else
        (*rear)->next = temp;
    *rear = temp;
}

// removes an element from front of queue
void deque(Node** front, Node** rear)
{
    Node* temp;
    // if queue is empty
    if (*front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        temp = *front;
        *front = temp->next;
        free(temp);
        if (*front == NULL)
            *rear = NULL;
    }
}

// displays content of queue
void display(Node* temp)
{
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int count(Node* queue)
{
    int c=0;
    while(queue != NULL)
    {
        queue = queue->next;
        c++;
    }
    return c;
}

int main()
{
    Node* front;
    Node* rear;
    int a,b;
    front = NULL;
    rear = NULL;
    enque(&front, &rear, 2);
    enque(&front, &rear, 3);
    display(front);
    deque(&front, &rear);
    printf("\n");
    display(front);
}