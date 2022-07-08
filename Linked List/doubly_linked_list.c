#include <stdio.h>
#include <stdlib.h>

// A structure to contain a node attributes
struct node
{
    int value;
    struct node* next;
    struct node* prev;
};

typedef struct node Node;

// Allocates memory for a new node
Node* newNode(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

// inserts a node at the end of the list
void insertEnd(Node** head, int value)
{
    Node *temp;
    temp = *head;
    // checks if there is no node
    if(*head == NULL)
    {
        /* if true, creates a new node and head pointer is pointed to the newly 
        created node.*/
        temp = newNode(value);
        *head = temp;
    }
    else
    {
        /* if true, traverses till the end of list, creates a new node and then point 
        the last node to new node.*/
        while(temp->next != NULL)
            temp = temp->next;
        Node* p = newNode(value);
        p->prev = temp;
        temp->next = p;
    }
}

void insertBegin(Node** head, int value)
{
    /* creates a new node, points new node to first node of the list and then head
    points to this new node.*/
    Node* temp;
    temp = newNode(value);
    (*head)->prev = temp;
    temp->next = *head;
    *head = temp;
}

// deletes a node from the list
void delete(Node** head, int key)
{
    Node* temp;
    temp = *head;
    // if only a single node is present
    if(temp->next == NULL && temp->value == key)
    {
        *head = NULL;
        free(temp);
        return;
    }
    // if node to be deleted is at the beginning
    if(temp != NULL && temp->value == key)
    {
        *head = temp->next;
        temp->next->prev = NULL;
        free(temp);
        return;
    }
    // if node to be deleted is in between
    while(temp != NULL && temp->value != key)
    {
        temp = temp->next;
    }

    // if the node to be deleted is at the end
    if(temp->next == NULL && temp->value == key)
    {
        temp->prev->next = NULL;
        free(temp);
        return;
    }

    if(temp == NULL)
    {
        printf("Key is not present\n");
        return;
    }
    
    // removing the node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void print_list(Node* head)
{
    printf("Forward: ");
    while(head != NULL)
    {
        printf("%d ",head->value);
        if(head->next == NULL)
            break;
        head = head->next;
    }
    printf("\nReverse: ");
    while(head != NULL)
    {
        printf("%d ",head->value);
        head = head->prev;
    }
}

int main()
{
    Node* head = NULL;
    insertEnd(&head,4);
    insertEnd(&head,5);
    insertBegin(&head,3);
    insertBegin(&head,1);
    print_list(head);
    delete(&head,4);
    delete(&head,1);
    printf("\n");
    print_list(head);
}