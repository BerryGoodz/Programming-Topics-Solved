#include <iostream>

using namespace std;

struct Node
{
    Node* left, *right, *nextRight;
    int data;
    Node(int data)
    {
        this -> data = data;
        left = NULL, right = NULL, nextRight = NULL;
    }
};
void connectBST(Node *root)
{
    if(root == NULL) return;
    if(root -> left != NULL)
    {
        root -> left -> nextRight = root -> right;
    }
    if(root -> right != NULL)
    {
        root -> right -> nextRight = root -> nextRight ? root -> nextRight -> left : NULL;
    }
    connectBST(root -> left);
    connectBST(root -> right);
}
int main ()
{
    Node *root = new Node(4);
    root -> left = new Node(5);
    root -> right = new Node(6);
    root -> left -> left = new Node(3);
    root -> right -> left = new Node(8);
    connectBST(root);
    return 0;
}
