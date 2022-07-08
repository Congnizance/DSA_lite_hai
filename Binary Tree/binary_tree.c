#include <stdio.h>
#include <stdlib.h>

// structure definition to store node variables 
struct node
{
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

// Allocates memory for a new node
Node* newNode(int value)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node* insert()
{
    int value;
    scanf("%d",&value);
    if(value == -1)
        return NULL;
    
    Node* temp = newNode(value);
    printf("Enter left child of : %d\n",value);
    temp->left = insert();
    printf("Enter right child of : %d\n",value);
    temp->right = insert();
}

void inorder(Node* root)
{
    if(root->left != NULL)
        inorder(root->left);
    printf("%d ",root->value);
    if(root->right != NULL)
        inorder(root->right);
}

int main()
{
    Node* root = NULL;
    root = insert();
    inorder(root);
}