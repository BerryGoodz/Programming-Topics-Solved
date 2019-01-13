#include <iostream>
#include <stack>
using namespace std;

void findNextLargerElement(int arr[], int n)
{
    stack<int> stacks;
    int i = 1;
    stacks.push(arr[0]);
    while(i < n)
    {
        if(stacks.empty())
        {
            stacks.push(arr[i]);
            i ++;
            continue;
        }
        if(stacks.top() < arr[i])
        {
            cout << stacks.top() << " --> " << arr[i] << endl;
            stacks.pop();
        }
        else
        {
            stacks.push(arr[i]);
            i ++;
        }
    }
    while(!stacks.empty())
    {
        cout << stacks.top() << " --> " << "-1" << endl;
        stacks.pop();
    }
}
int main ()
{
    int arr[] = {2,5,3,6,7,3,4,1,3};
    findNextLargerElement(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
