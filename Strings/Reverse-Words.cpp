#include <iostream>

using namespace std;

string reverseString(string s)
{
    for(int i = 0; i < s.size() / 2; i ++)
    {
        int endIndex = s.size() - i - 1;
        char temp = s[i];
        s[i] = s[endIndex];
        s[endIndex] = temp;
    }
    return s;
}
string reverseWords(string s)
{
    int j = 0;
    for(int i = 0; i < s.size(); i ++)
    {
        if(s[i] == ' ')
        {
            for(int p = j; p < (i - j) / 2 + j; p ++)
            {
                char temp = s[p];
                int endIndex = i - p - 1 + j;
                s[p] = s[endIndex];
                s[endIndex] = temp;
            }
            j = i + 1;
        }
    }
    return reverseString(s);
}

int main()
{
    string s = "I will be better ";
    cout << reverseWords(s);
    return 0;
}
