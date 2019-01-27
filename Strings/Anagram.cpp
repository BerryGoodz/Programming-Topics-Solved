#include <iostream>
#include <unordered_map>
using namespace std;

/*
anagram is a word that can be arranged by other word by switching the order of the alphabets.
For example,
abc - acb
Listen - Silent
Triangle - Integral

*/
bool isAnagram(string first, string second)
{
    unordered_map<char, int> um;

    int firstSize = first.size();
    int secondSize = second.size();
    if(firstSize != secondSize) return false;
    for(int i = 0; i < firstSize; i ++) //add the characters of first string and subtract characters of other string.
    {
        um[first[i]] ++;
        um[second[i]] --;
    }
    for (unordered_map<char, int>::const_iterator it = um.begin(); it != um.end(); ++it)
        if (it->second != 0) return false;//if the character number is not zero, then the strings are not same.

    return true;
}
int main()
{
    string s = "listen";
    string g = "silent";
    cout << isAnagram(s, g);
    return 0;
}
