#include <iostream>

using namespace std;

//editing from "Apple" to "Pineapple" takes 4 operations (4 adding)
//recursive
/*int minimumEdit(string s1, string s2, int m, int n)
{
    if(m == 0) return n;
    if(n == 0) return m;
    if(s1[m - 1] == s2[n - 1])
    {
        return minimumEdit(s1, s2, m - 1, n - 1);
    }
    else
    {
        return min(1 + minimumEdit(s1, s2, m - 1, n), min(1 + minimumEdit(s1, s2, m, n - 1), 1 + minimumEdit(s1, s2, m - 1, n - 1)));
    }
}*/
int minimumEdit(string s1, string s2)
{
    int size1 = s1.size();
    int size2 = s2.size();
    int table[size1 + 1][size2 + 1];

    for(int i = 0; i <= size1; i ++)
        table[i][0] = i;
    for(int i = 0; i <= size2; i ++)
        table[0][i] = i;

    for(int i = 1; i <= size1; i ++)
    {
        for(int j = 1; j <= size2; j ++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1];
            }
            else
            {
                table[i][j] = 1 + min(table[i - 1][j - 1], min(table[i - 1][j], table[i][j - 1]));
            }
        }
    }
    return table[size1][size2];
}
int main ()
{
    string s1 = "pineapple";
    string s2 = "poineapple";
    cout << minimumEdit(s1, s2);
    return 0;
}
