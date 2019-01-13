#include <iostream>

using namespace std;

/*
    Rod cutting problem
    value[] = {2,3,5,8,11,12,14}
    length[] = {1,2,3,4,5,6,7}
    rod length = 5


*/
//recursive version
/*int longestRod(int value[], int length)
{
    if(length <= 0) return 0;
    int maxi = 0;
    int current = 0;
    for(int i = 0; i < length; i ++)
    {
        current = value[i] + longestRod(value, length - i - 1);
        if(maxi < current) maxi = current;
    }
    return maxi;
}*/
//tabulated version
int longestRod(int value[], int length)
{
    int table[length + 1];
    for(int i = 0; i <= length; i++)
        table[i] = 0;
    for(int i = 1; i <= length; i ++)
    {
        for(int j = 1; j <= i; j ++)
            table[i] = max(table[i], value[j - 1] + table[i - j]);
    }
    return table[length];
}
int main ()
{
    int value[] = {2,3,8,8,12,12,14};
    cout << longestRod(value, 6);
    return 0;
}
