#include <iostream>

using namespace std;

/*
    1 = 1
    2 = 2
    3 = 3
    4 = 4
    3 * 2 = 6
    3 * 3 = 9
    2 * 2 * 3 = 12
    2 * 3 * 3 = 18
    3 * 3 * 3 = 27
    2 * 2 * 3 * 3 = 36
    2 * 3 * 3 * 3 = 54
    3 * 3 * 3 * 3 = 81



*/
int productRod(int n)
{
    if(n <= 0) return 1;
    if(n - 3 != 1 && n - 3 >= 0) return 3 * productRod(n - 3);
    if(n - 2 != 1 && n - 2 >= 0) return 2 * productRod(n - 2);
    return n;
}
int main ()
{
    cout << productRod(15);
    return 0;
}
