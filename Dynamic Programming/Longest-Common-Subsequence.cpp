#include <iostream>

using namespace std;

/*
    abcdef
    bdefgg
    def


*/
//recursive
/*
int longestCommonSub(string s1, string s2, int n1, int n2)
{
    if(n1 < 0 || n2 < 0) return 0;
    if(s1[n1] == s2[n2]) return 1 + longestCommonSub(s1, s2, n1 - 1, n2 - 1);
    return max(longestCommonSub(s1, s2, n1 - 1, n2), longestCommonSub(s1, s2, n1, n2 - 1));
}
*/
//tabulated
int longestCommonSub(string s1, string s2, int n1, int n2)
{
    int table[n1 + 1][n2 + 1];
    for(int i = 0; i <= n1; i ++)
        for(int j = 0; j <= n2; j ++)
        table[i][j] = 0;
    int maxi = 0;
    for(int i = 1; i <= n1; i ++)
    {
        for(int j = 1; j <= n2; j ++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                if(maxi < table[i][j]) maxi = table[i][j];
            }
            else table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    for(int i = 0; i <= n1; i ++)
    {


        for(int j = 0; j <= n2; j ++)
        {
            cout << table[i][j] << " ";

        }
        cout << endl;
    }
    return maxi;
}
int main ()
{
    string s1 = "godop";
    string s2 = "piodoppp";
    cout << longestCommonSub(s1, s2, s1.size(), s2.size());
    return 0;
}
