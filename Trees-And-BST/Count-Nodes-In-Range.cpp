#include <iostream>

using namespace std;

struct Node
{
    Node* left, *right;
    int data;
    Node(int data)
    {
        this -> data = data;
        left = NULL, right = NULL;
    }
};
int count_BST_nodes_in_range(Node *root, int low, int high, int &sum)
{
    if(root == NULL) return 0;
    int data = root -> data;
    if(data >= low && data <= high)
    {
        sum ++;
    }
    count_BST_nodes_in_range(root -> left, low, high, sum);
    count_BST_nodes_in_range(root -> right, low, high, sum);
    return sum;
}
int main ()
{
    Node *root = new Node(5);
    root -> left = new Node(3);
    root -> right = new Node(6);
    root -> left -> right = new Node(7);
    root -> right -> right = new Node(60);
    int counts = 0;
    cout << count_BST_nodes_in_range(root, 0, 9, counts);

    return 0;
}
