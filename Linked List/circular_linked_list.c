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
        temp->next = *head;
        return;
    }
    
    temp = newNode(value);
    temp->next = (*head)->next;
    (*head)->next = temp;
    *head = temp;
}

// inserts a node at begining of the list
void insertBegin(Node** head, int value)
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
        temp->next = *head;
        return;
    }

    temp = newNode(value);
    temp->next = (*head)->next;
    (*head)->next = temp;
}

// prints the linked list
void print_list(Node* head)
{
    // traverses the entire list and print them simultaneously.
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node* p;
    p = head->next;
    do
    {
        printf("%d ",p->value);
        p = p->next;
    }
    while(p != head->next);
}

// search a node containing required element in the list
int search(Node* head, int key)
{
    // traverses the list and checks if any node value matches the key.
    while(head != NULL)
    {
        // if true, 1 is returned.
        if(head->value == key)
            return 1;
        head = head->next;
    }
    printf("Key is not present: ");
    return 0;
}

// deletes a node from the list
// void delete(Node** head, int key)
// {
//     if(*head == NULL)
//         return;

//     Node* temp;
//     Node* prev;
//     temp = *head;
    
    
//     // if node to be deleted is at the beginning
//     while(temp->value != key)
//     {
//         if(temp->next == *head)
//         {
//             printf("Key is not present\n");
//             return;
//         }
//         prev = temp;
//         temp = temp->next;
//     }

//     // if a single node is present
//     if(temp->next == *head)
//     {
//         head = NULL;
//         free(temp);
//         return;
//     }

//     if(temp == *head)
//     {
//         prev = *head;
//         while(prev->next != *head)
//             prev = prev->next;
//         *head = temp->next;
//         prev->next = *head;
//         free(temp);
//         return;
//     }

//     // check if node is last node
//     else if (temp->next == *head && temp == *head)
//     {
//         prev->next = *head;
//         free(temp);
//         return;
//     }
//     else
//     {
//         prev->next = temp->next;
//         free(temp);
//         return;
//     }
// }

int main()
{
    Node* head = NULL;
    insertBegin(&head,1);
    insertBegin(&head,2);
    insertEnd(&head,3);
    insertEnd(&head,4);
    insertEnd(&head,5);
    print_list(head);
    // delete(&head,2);
    // delete(&head,5);
    // printf("%d\n",search(head,5));
    // reverse_list(&head);
    printf("\n");
    print_list(head);
}