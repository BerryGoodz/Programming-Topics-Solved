#include <iostream>

using namespace std;

int getMax(int a, int b);
int longestPalindromeUtil(string &s, int length, int start, int ending)
{
    if(start < 0 || ending >= s.size()) return length;
    int result1 = 0;
    if(s[start] == s[ending])
    {
        result1 = longestPalindromeUtil(s, length + 2, start - 1, ending + 1);
    }
    return getMax(longestPalindromeUtil(s, length, start + 1, ending + 1), result1);
}
int longestPalindrome(string& s)
{
    return getMax(longestPalindromeUtil(s, 0, 0, 1), longestPalindromeUtil(s, 1, 0, 2));
}
int getMax(int a, int b)
{
    return a > b ? a : b;
}
int main ()
{
    string s1 = "abbaeidlsabcba";
    string s2 = "abba";
    string s3 = "ggiillmmmmmmmpp";
    cout << longestPalindrome(s1) << endl;
    cout << longestPalindrome(s2) << endl;
    cout << longestPalindrome(s3) << endl;
    return 0;
}
