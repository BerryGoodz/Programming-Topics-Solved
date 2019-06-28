#include <iostream>
#include <stack>
using namespace std;


int main()
{
    stack<int> myStack1, myStack2;
    int temp;
    int input;
    cin >> input;
    for(int i = 0; i < input; i ++)
    {
        int n;
        cin.clear();
        cin >> n;
        myStack1.push(n);
    }


    myStack2.push(myStack1.top());
    myStack1.pop();

    while(!myStack1.empty())
    {
        if(myStack1.top() < myStack2.top())
        {
            myStack2.push(myStack1.top());
            myStack1.pop();
        }
        else
        {
            temp = myStack1.top();
            while(!myStack2.empty() && myStack2.top() < temp)
            {
                myStack1.push(myStack2.top());
                myStack2.pop();
            }
            myStack2.push(temp);
            while(myStack1.top() != temp)
            {
                myStack2.push(myStack1.top());
                myStack1.pop();
            }
            myStack1.pop();
        }
   }




    while(!myStack2.empty())
    {
        cout << myStack2.top() << endl;
        myStack2.pop();
    }
    return 0;
}
