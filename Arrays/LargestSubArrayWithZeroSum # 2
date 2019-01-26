#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubArrayWithZeroSum(int arr[], int n)
{
    unordered_map<int, int> um;
    int sum = 0;
    int longestSum = 0;
    um[0] = -1;
    for(int i = 0; i < n; i ++)
    {
        sum += arr[i];
        unordered_map<int, int>::const_iterator it = um.find(sum);
        if(it != um.end())
        {
            int newSum = i - it -> second;
            if(newSum > longestSum) longestSum = newSum;
        }
        else um[sum] = i;
    }
    return longestSum;
}
int main()
{
    int arr[] = {11, 4, -3, 100, 5, -2, 6, -4, 3, -9, 3, -1, -1, -1, 6, 2, -2};
    cout << longestSubArrayWithZeroSum(arr, sizeof(arr) / sizeof(arr[0]));
    unordered_map<int, int> um;
    return 0;
}
//5, 6, -6, 7, -4, 2, -3, -2, 19, -2, 9, -9
