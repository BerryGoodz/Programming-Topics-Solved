#include <iostream>
#include <stack>
using namespace std;

// check if the parenthesis are balanced
// "()(){}" - true
// "({)}" - false
bool checkParenBalance(string s)
{
    stack<char> chars;
    for(int i = 0; i < s.size(); i ++)
    {
        char charsTop;
        if(!chars.empty())
        {
            charsTop = chars.top();
        }
        if(s[i] == '[' || s[i] == '('|| s[i] == '{') chars.push(s[i]);
        else if(charsTop == '[' && s[i] == ']') chars.pop();
        else if(charsTop == '[' && s[i] != ']') return false;

        else if(charsTop == '(' && s[i] == ')') chars.pop();
        else if(charsTop == '(' && s[i] != ')') return false;

        else if(charsTop == '{' && s[i] == '}') chars.pop();
        else if(charsTop == '{' && s[i] != '}') return false;
    }
    if(!chars.empty()) return false;
    return true;
}
int main ()
{
    string s = "(((})))";
    cout << checkParenBalance(s);
    return 0;
}
