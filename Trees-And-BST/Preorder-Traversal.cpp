#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    Node *right, *left;
    int data;
    Node(int data)
    {
        this -> data = data;
        right = NULL;
        left = NULL;
    }
};
void nonRecursivePreOrderTraversal(Node *root)
{
    stack<Node *> stacks;
    stacks.push(root);
    while(!stacks.empty())
    {
        Node *temp = stacks.top();
        stacks.pop();
        cout << temp -> data << " ";
        if(temp -> right != NULL)
        stacks.push(temp -> right);
        if(temp -> left != NULL)
        stacks.push(temp -> left);
    }
}
void recursivePreOrderTraversal(Node *root)
{
    if(root == NULL) return;
    cout << root -> data << " ";
    recursivePreOrderTraversal(root -> left);
    recursivePreOrderTraversal(root -> right);
}
int main ()
{
    Node *root = new Node(4);
    root -> left = new Node(2);
    root -> left -> right = new Node(6);
    root -> left -> left = new Node(1);
    root -> right = new Node(5);
    root -> right -> right = new Node(9);
    recursivePreOrderTraversal(root);
    cout << endl;
    nonRecursivePreOrderTraversal(root);
    return 0;
}
