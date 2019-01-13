#include <iostream>

using namespace std;

struct Node
{
    Node *next;
    int data;
    Node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};

class linkedList
{
    private:
        Node *head;
    public:
        linkedList()
        {
            head = NULL;
        }
        void push(int data)
        {
            Node *newNode = new Node(data);
            if(head == NULL)
            {
                head = newNode;
            }
            else
            {
                newNode -> next = head;
                head = newNode;
            }
        }
        void reverseLinkedList()
        {
            Node *current = head;
            Node *next = NULL;
            Node *prev = NULL;
            while(current != NULL)
            {
                next = current -> next;
                current -> next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
        void printLinkedList()
        {
            Node *temp = head;
           while(temp != NULL)
           {
               cout << temp -> data;
               if(temp -> next != NULL) cout <<"->";
                temp = temp -> next;
           }
           cout << endl;
        }
};
int main()
{
    linkedList l;
    l.push(4);
    l.push(6);
    l.push(2);
    l.push(1);
    l.push(44);
    l.push(99);
    l.printLinkedList();
    l.reverseLinkedList();
    l.printLinkedList();
    return 0;
}
