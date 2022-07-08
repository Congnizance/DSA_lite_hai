#include <stdio.h>
#include <stdlib.h>

// A structure to contain a node attributes
struct node
{
    int value;
    struct node* next;
};

typedef struct node Node;

// Allocates memory for a new node
Node* newNode(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

// inserts a node at begining of the list
void push(Node** head, int value)
{
    /* creates a new node, points new node to first node of the list and then head
    points to this new node.*/
    Node* temp;
    temp = newNode(value);
    temp->next = *head;
    *head = temp;
}

// prints the linked list
int peek(Node* head)
{
    if(head == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return head->value;
}

// deletes a node from the list
void pop(Node** head)
{
    Node* temp;
    temp = *head;
    // deleting head node
    if(temp != NULL)
    {
        *head = temp->next;
        free(temp);
        return;
    }
}

int isEmpty(Node *head)
{
    if(head == NULL)
        return 1;
    return 0;
}

int main()
{
    Node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    pop(&head);
    pop(&head);
    pop(&head);
    printf("%d\n",peek(head));
    printf("%d\n",isEmpty(head));
}