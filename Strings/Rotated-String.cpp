#include <iostream>
#include <string>
using namespace std;

bool isRotateAble(string s1, string s2)
{
    if(s1 == s2) return true;
    for(int i = 1; i < s2.size(); i ++)
    {
        string copyString = s2;
        int length = s2.size() - i;
        string subString = s2.substr(i, length);
        copyString.erase(i, length);
        copyString.insert(0, subString);
        if(s1 == copyString)
        {
            cout << "Rotate-able at index " << i;
            return true;
        }
    }
    cout << "Not rotate-able";
    return false;
}
int main ()
{
    string s1 = "clockwise";
    string s2 = "wiseclock";
    isRotateAble(s1, s2);
    cout << endl;
    string ex1 = "amazon";
    string ex2 = "azonam";
    isRotateAble(ex1, ex2);
    return 0;
}
