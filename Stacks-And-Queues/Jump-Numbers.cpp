#include <iostream>
#include <stack>
using namespace std;

//jump numbers are numbers that its digits differ by one
void jumpNumbersUtil(int n, int i)
{
    stack<int> stacks;
    stacks.push(i);
    int currentNum = i;
    while(!stacks.empty())
    {
        if(currentNum <= n)
        {
            cout << currentNum << endl;
            int newNum = currentNum * 10;
            if(currentNum % 10 == 0)
            {
                stacks.push(newNum + 1);
            }
            else if(currentNum % 10 == 9)
            {
                stacks.push(newNum + 8);
            }
            else
            {
                stacks.push(newNum + currentNum % 10 + 1);
                stacks.push(newNum + currentNum % 10 - 1);
            }
        }
        currentNum = stacks.top();
        stacks.pop();
    }
}
void jumpNumbers(int n)
{
    cout << "0" << endl;
    for(int i = 1; i <= 9; i ++)
    {
        jumpNumbersUtil(n, i);
    }
}
int main ()
{
    jumpNumbers(40);
    return 0;
}
