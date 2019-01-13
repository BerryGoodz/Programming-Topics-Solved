#include <iostream>

using namespace std;
/*
    add 1, 3, 5 to make 7

    1 + 1 + 1 + 1 + 1 + 1 + 1
    3 + 3 + 1
    5 + 1 + 1
    3 + 1 + 1 + 1 + 1


*/
int getNumberSum(int sum)
{
    int table[sum + 1];
    table[0] = 1;
    for(int i = 1; i <= sum; i ++)
    {
        int n1 = 0, n2 = 0, n3 = 0;
        if(i - 1 >= 0) n1 = table[i - 1];
        if(i - 3 >= 0) n2 = table[i - 3];
        if(i - 5 >= 0) n3 = table[i - 5];
        table[i] = n1 + n2 + n3;
        cout << table[i] << endl;
    }
    return table[sum];
}
int main ()
{
    getNumberSum(15);
    return 0;
}
