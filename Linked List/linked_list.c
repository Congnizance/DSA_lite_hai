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
    }
    else
    {
        /* if true, traverses till the end of list, creates a new node and then point 
        the last node to new node.*/
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode(value);
    }
}

// inserts a node at begining of the list
void insertBegin(Node** head, int value)
{
    /* creates a new node, points new node to first node of the list and then head
    points to this new node.*/
    Node* temp;
    temp = newNode(value);
    temp->next = *head;
    *head = temp;
}

// prints the linked list
void print_list(Node* head)
{
    // traverses the entire list and print them simultaneously.
    while(head != NULL)
    {
        printf("%d ",head->value);
        head = head->next;
    }
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
void delete(Node** head, int key)
{
    Node* temp;
    temp = *head;
    // if node to be deleted is at the beginning
    if(temp != NULL && temp->value == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    // if node to be deleted is in between or at the end
    Node* prev;
    while(temp != NULL && temp->value != key)
    {
        prev = temp; // stores previous node address
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Key is not present\n");
        return;
    }
    
    // removing the node
    prev->next = temp->next;
    free(temp);
}

// reverses a linked list
void reverse_list(Node** head)
{
    Node* prevNode;
    Node* currNode;
    Node* temp;
    temp = *head;
    if(temp != NULL)
    {
        prevNode = temp;
        currNode = temp->next;
        temp = temp->next;
        prevNode->next = NULL;
        while(temp != NULL)
        {
            temp = temp->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = temp;
        }
        *head = prevNode;
    }
}

int len(struct node* head)
{
    int count=0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// struct node* rev(struct node* head, int k)
// {
//     struct node* temp;
//     temp = head;
//     while(temp != NULL)
//     {
//         struct node* prevNode;
//         struct node* currNode;
//         // struct node* temp;
//         // temp = head;
//         prevNode = temp;
//         currNode = temp->next;
//         if(temp == head)
//             prevNode->next = NULL;
//         else
//             prevNode->next = head;
//         temp = temp->next;
//         int p=k;
//         while(temp != NULL && p > 1)
//         {
//             temp = temp->next;
//             currNode->next = prevNode;
//             prevNode = currNode;
//             currNode = temp;
//             p--;
//         }
//         head = prevNode;
//     }
//     return head;
// }

int main()
{
    Node* head = NULL;
    insertEnd(&head,1);
    insertEnd(&head,2);
    insertEnd(&head,3);
    insertEnd(&head,4);
    insertEnd(&head,5);
    insertEnd(&head,6);
    insertEnd(&head,7);
    // delete(&head,2);
    // printf("%d\n",search(head,5));
    // reverse_list(&head);
    print_list(head);
    // print_list(rev(head,3));

}