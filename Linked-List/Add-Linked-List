#include <iostream>
#include <stack>

// add numbers represented by two linked lists
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        data = this -> data;
        next = NULL;
    }
};
void push(Node **head_ref, int data)
{
    Node *newNode = new Node(data);
    newNode -> data = data;
    newNode -> next = (*head_ref);
    (*head_ref) = newNode;
}
void printLinkedList(Node *root)
{
    while(root != NULL)
    {
        cout << root -> data;
        if(root -> next != NULL) cout << "->";
        root = root -> next;
    }
}
int addLinkedList(Node *root, Node *root2)
{
    stack<int> stack1, stack2;

    while(root != NULL)
    {
        stack1.push(root -> data);
        root = root -> next;
    }
    while(root2 != NULL)
    {
        stack2.push(root2 -> data);
        root2 = root2 -> next;
    }
    int sum = 0;
    int digit = 1;
    while(!stack1.empty())
    {
        sum += stack1.top() * digit;
        stack1.pop();
        digit *= 10;
    }
    digit = 1;
    while(!stack2.empty())
    {
        sum += stack2.top() * digit;
        stack2.pop();
        digit *= 10;
    }
    return sum;
}
int main ()
{
    Node *root = NULL;
    Node *root2 = NULL;
    push(&root, 3);
    push(&root, 6);
    push(&root, 8);
    push(&root2, 9);
    push(&root2, 5);
    printLinkedList(root);
    cout << endl;
    printLinkedList(root2);
    cout << endl;
    cout << "Sum is " << addLinkedList(root, root2);
    return 0;
}
