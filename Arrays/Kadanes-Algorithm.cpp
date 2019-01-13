#include <iostream>

using namespace std;

int getMax(int a, int b);
int biggestContiguousSubArray(int arr[], int n)
{
    int max_so_far = arr[0];
    int max_end_here = arr[0];
    for(int i = 1; i < n; i ++)
    {
        max_end_here = getMax(max_end_here + arr[i], arr[i]);
        max_so_far = getMax(max_so_far, max_end_here);
    }
    return max_so_far;
}
int getMax(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int arr[6] = {5,2,8,-4,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << biggestContiguousSubArray(arr, n);
    return 0;
}
