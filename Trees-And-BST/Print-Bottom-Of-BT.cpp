#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node
{
    Node *right, *left;
    int data;
    int hd;
    Node(int data)
    {
        this -> data = data;
        left = right = NULL;
    }
};
void printBottomOfBT(Node* root)
{
    root -> hd = 0;
    queue<Node *> nodeQ;
    map<int, int> bottomNodes;
    nodeQ.push(root);
    while(!nodeQ.empty())
    {
        Node *temp = nodeQ.front();
        nodeQ.pop();
        bottomNodes[temp -> hd] = temp -> data;
        if(temp -> left != NULL)
        {
            temp -> left -> hd = temp -> hd - 1;
            nodeQ.push(temp -> left);
        }
        if(temp -> right != NULL)
        {
            temp -> right -> hd = temp -> hd + 1;
            nodeQ.push(temp -> right);
        }
    }
    for(map<int, int>::iterator it = bottomNodes.begin(); it != bottomNodes.end(); ++ it)
    {
        cout << it -> second << " ";
    }
}
int main()
{
    Node *root = new Node(2);
    root -> left = new Node(3);
    root -> right = new Node(4);
    root -> left -> left = new Node(6);
    root -> left -> right = new Node(7);
    printBottomOfBT(root);
    return 0;
}
