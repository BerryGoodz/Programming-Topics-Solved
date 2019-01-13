#include <iostream>

using namespace std;

/*
    Ugly number is a number with only prime factors of 2, 3, or 5

*/
int getMin(int a, int b, int c)
{
    return min(min(a,b),c);
}
int uglyNumber(int n)
{
    if(n < 1) return -1;
    int i2 = 0, i3 = 0, i5 = 0;
    int ugly[n];
    ugly[0] = 1;
    int next_multiple_of_two = 2;
    int next_multiple_of_three = 3;
    int next_multiple_of_five = 5;
    cout << 1 << endl;
    for(int i = 1; i < n; i ++)
    {
        int next_ugly_n = getMin(next_multiple_of_two, next_multiple_of_three, next_multiple_of_five);
        ugly[i] = next_ugly_n;
        if(next_ugly_n == next_multiple_of_two)
        {
            i2 ++;
            next_multiple_of_two = ugly[i2] * 2;
        }
        if(next_ugly_n == next_multiple_of_three)
        {
            i3 ++;
            next_multiple_of_three = ugly[i3] * 3;
        }
        if(next_ugly_n == next_multiple_of_five)
        {
            i5 ++;
            next_multiple_of_five = ugly[i5] * 5;
        }
        cout << next_ugly_n << endl;
    }
    return ugly[n - 1];
}
int main ()
{
    uglyNumber(800);
    return 0;
}
