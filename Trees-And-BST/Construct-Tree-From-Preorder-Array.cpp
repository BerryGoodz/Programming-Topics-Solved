/* A O(n) program for construction of BST from preorder traversal */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// A utility function to create a node
struct node* newNode (int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}
// A utility function to print inorder traversal of a Binary Tree
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
node* constructTreeUtil(int pre[], int* index, int key, int low, int high, int s)
{
    node *root = NULL;
    if(*index >= s)
    return NULL;

    if(key > low && key < high)
    {
        *index = *index + 1;
        root = newNode(key);
        if(*index < s)
        {
        root -> left = constructTreeUtil(pre, index, pre[*index], low, key, s);
        root -> right = constructTreeUtil(pre, index, pre[*index], key, high, s);
        }
    }
    return root;
}
node* constructTreeUtil2(int pre[], int index, int key, int low, int high, int s) 
{
    // if the index is not a pointer with address, the same index will be repeated and stop the 
    // recursion without fully iterating through the array
    node *root = NULL;
    if(index >= s)
    return NULL;

    if(key > low && key < high)
    {
        index = index + 1;
        root = newNode(key);
        if(index < s)
        {
        root -> left = constructTreeUtil2(pre, index, pre[index], low, key, s);
        root -> right = constructTreeUtil2(pre, index, pre[index], key, high, s);
        }
    }
    return root;
}
node* constructTree(int pre[], int s)
{
    int index = 0;
    return constructTreeUtil(pre, &index, pre[0], -1000, 1000, s);
}
// Driver program to test above functions
int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    struct node *root = constructTree(pre, size);

    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);

    return 0;
}
