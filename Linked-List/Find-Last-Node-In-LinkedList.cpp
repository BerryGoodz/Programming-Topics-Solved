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
class LinkedList
{
    private:
        Node *head = NULL;
    public:
        void push(int data)
        {
            Node *temp = new Node(data);
            if(head == NULL)
            {
                head = temp;
            }
            else
            {
                temp -> next = head;
                head = temp;
            }
        }
        int findLast(int n)
        {
            Node *slow = head;
            Node *fast = head;
            int counter = 0;
            while(fast != NULL)
            {
                fast = fast -> next;
                if(counter >= n)
                {
                    slow = slow -> next;
                }
                counter ++;
            }
            return slow -> data;
        }
};
int main()
{
    LinkedList l;
    l.push(4);
    l.push(1);
    l.push(6);
    cout << l.findLast(1);
    return 0;
}
