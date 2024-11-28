#include <stdlib.h>

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Time Complexity: O(h) where h is height of tree
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->val)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->val)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
// Time Complexity: O(n), where n is the number of nodes in the tree
int countNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
// Time Complexity: O(n), where n is the number of nodes in the tree
int countLeafNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Time Complexity: O(n), where n is the number of nodes in the tree
int findHeight(struct Node *root)
{
    if (root == NULL)
        return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Time Complexity: O(h) where h is height of tree
int findMin(struct Node *root)
{
    if (root == NULL)
    {
        return -1; 
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->val;
}
// Time Complexity: O(h) where h is height of tree
struct Node *delNode(struct Node *root, int x)
{
    if (root == NULL)
        return root;
    if (root->val > x)
        root->left = delNode(root->left, x);
    else if (root->val < x)
        root->right = delNode(root->right, x);
    else
    {
        if (root->left == NULL)
        { // Case 1: Node has no left child (or is a leaf node)
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        { // Case 2: Node has no right child
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *succ = root->right; // Case 3: Node has two children
        while (succ->left != NULL)
            succ = succ->left;
        root->val = succ->val;
        root->right = delNode(root->right, succ->val);
    }
    return root;
}

// Time Complexity: O(n), where n is the number of nodes
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);   
        printf("%d ", root->val);      
        inOrderTraversal(root->right); 
    }
}

// Time Complexity: O(n), where n is the number of nodes
void preOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);       
        preOrderTraversal(root->left);  
        preOrderTraversal(root->right); 
    }
}

// Time Complexity: O(n), where n is the number of nodes
void postOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);  
        postOrderTraversal(root->right); 
        printf("%d ", root->val);       
    }
}
