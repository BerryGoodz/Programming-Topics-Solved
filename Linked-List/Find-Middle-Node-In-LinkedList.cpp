#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};
int getMiddle(Node *root)
{
    int n = 0;
    Node *temp1 = root;
    while(temp1 -> next != NULL)
    {
        temp1 = temp1 -> next;
        n ++;
    }
    int halfPoint = n / 2;
    Node *temp2 = root;
    while(halfPoint > 0)
    {

        temp2 = temp2 -> next;
        halfPoint --;
    }
    return temp2 -> data;
}
int main()
{
    Node *root = new Node(4);
    root -> next = new Node(7);
    root -> next -> next = new Node(6);
    root -> next -> next -> next = new Node(10);
    root -> next -> next -> next -> next = new Node(12);
    cout << getMiddle(root);
    return 0;
}
