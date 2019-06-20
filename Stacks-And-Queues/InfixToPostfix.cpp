#include <iostream>
#include <stack>
using namespace std;

string infixToPostfix(string s)
{
    stack<char> myStack;
    string answer = "";
    for(int i = 0; i < s.size(); i ++)
    {
        if(s[i] == '(')
        {
            myStack.push(s[i]);
        }
        else if(s[i] >= 48 && s[i] <= 57)
        {
            answer += s[i];
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*')
        {
            if(!myStack.empty() && myStack.top() == '*')
            {
                answer += myStack.top();
                myStack.pop();
            }
            myStack.push(s[i]);

        }
        else if(s[i] == ')')
        {
            while(!myStack.empty())
            {
                if(myStack.top() != '(') answer += myStack.top();
                myStack.pop();
            }
        }

    }
    while(!myStack.empty())
    {
        if(myStack.top() != '(') answer += myStack.top();
        myStack.pop();
    }
    return answer;
}
int main()
{
    //string s = "(5+4)*(3+3)";
    //string s = "3*9+4";
    // string s = "4+(3*2+8)-5";
    cout << infixToPostfix(s);

    return 0;
}
