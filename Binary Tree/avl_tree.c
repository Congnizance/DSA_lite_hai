#include <stdio.h>
#include <stdlib.h>

// structure definition to store node variables 
struct node
{
    int value;
    struct node *left;
    struct node *right;
    int height;
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


int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int height(Node* root)
{
    if(root == NULL)
        return -1;
    return max(height(root->left),height(root->right))+1;
}

void inorder(Node* root)
{
    if(root->left != NULL)
        inorder(root->left);
    printf("%d ",root->value);
    if(root->right != NULL)
        inorder(root->right);
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    // performing rotation
    x->right = y;
    y->left = T2;

    // update heights
    y->height = height(y);
    x->height = height(x);

    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    // performing rotation
    y->left = x;
    x->right = T2;

    // update heights
    y->height = height(y);
    x->height = height(x);

    return y;
}

int getBalance(Node* root)
{
    if(root == NULL)
        return 0;
    return height(root->left)-height(root->right);
}

Node* insert(Node* root, int value)
{
    if(root == NULL)
        return newNode(value);
    if(value < root->value)
        root->left = insert(root->left,value);
    else if(value > root->value)
        root->right = insert(root->right,value);
    else
        return root;
    
    // get height of node
    root->height = height(root);

    // check the balance factor
    int bF = getBalance(root);

    if(bF > 1 && value < root->left->value)
        return rightRotate(root);
    if(bF < -1 && value > root->right->value)
        return leftRotate(root);
    if(bF > 1 && value > root->left->value)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bF < -1 && value < root->right->value)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
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
    if(root == NULL)
        return root;
    // get height of node
    root->height = height(root);

    // check the balance factor
    int bF = getBalance(root);

    if(bF > 1 && value < root->left->value)
        return rightRotate(root);
    if(bF < -1 && value > root->right->value)
        return leftRotate(root);
    if(bF > 1 && value > root->left->value)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bF < -1 && value < root->right->value)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main()
{
    Node* root = NULL;
    root = insert(root,7);
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,8);
    root = insert(root,5);
    
    root = delete(root,4);
    root = delete(root,1);
    printf("%d\n",height(root));
    inorder(root);
}