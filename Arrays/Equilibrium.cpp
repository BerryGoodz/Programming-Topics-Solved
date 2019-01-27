#include <iostream>

using namespace std;

int findEqui(int arr[], int n)
{
    if(n < 3) return -1;
    for(int i = 1; i < n - 1; i ++)
    {
        int leftSum = 0;
        int rightSum = 0;
        for(int lhs = 0; lhs < i; lhs ++)
        {
            leftSum += arr[lhs];
        }
        for(int rhs = i + 1; rhs < n; rhs ++)
        {
            rightSum += arr[rhs];
        }
        if(rightSum == leftSum) return i;
    }
    return -1;
}
int main()
{
    int arr[] = {4,3,2,0,2,3,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findEqui(arr, n); //prints 4 because 4 + 3 + 2 + 0 == 3 + 6
    return 0;
}

