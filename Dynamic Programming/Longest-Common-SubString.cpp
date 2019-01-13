#include <iostream>

using namespace std;

int longestCommonSubString(string s1, string s2, int m, int n)
{
    int table[m + 1][n + 1];
    int max_so_far = 0;
    for(int i = 0; i <= m; i ++)
        for(int j = 0; j <= n; j ++)
        table[i][j] = 0;

    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                if(max_so_far < table[i][j]) max_so_far = table[i][j];
            }
        }
    }
    return max_so_far;
}
int main ()
{
    string s1 = "wowgorilla";
    string s2 = "eekgorillapop";
    cout << longestCommonSubString(s1, s2, s1.size(), s2.size());
    return 0;
}
