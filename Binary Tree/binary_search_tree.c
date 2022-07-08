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

Node* search(Node* root, int key)
{
    if(root == NULL)
        return NULL;
    if(root->value == key)
        return root;
    if(root->value > key)
        return search(root->left,key);
    else
        return search(root->right,key);
}

Node* insert(Node* root, int value)
{
    if(root == NULL)
        return newNode(value);
    if(value < root->value)
        root->left = insert(root->left,value);
    else if(value > root->value)
        root->right = insert(root->right,value);
    return root;
}

int minBST(Node* root)
{
    while(root->left != NULL)
        root = root->left;
    return root->value;
}

Node* delete(Node* root, int value)
{
    if(root == NULL)
        return root;
    if(value < root->value)
        root->left = delete(root->left,value);
    else if(value > root->value)
        root->right = delete(root->right,value);
    else
    {
        // Case 1: No child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if(root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Two children
        else
        {
            int data = minBST(root->right);
            root->value = data;
            root->right = delete(root->right,data);
        }
    }
    return root;
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
    root = insert(root,7);
    insert(root,3);
    insert(root,4);
    insert(root,8);
    insert(root,5);
    insert(root,10);
    if(search(root,10) != NULL)
        printf("Found it\n");
    else
        printf("Not in tree\n");
    printf("%d\n",minBST(root));
    root = delete(root,10);
    inorder(root);
}