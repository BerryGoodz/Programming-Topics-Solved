#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubArrayWithZeroSum(int arr[], int n)
{
    unordered_map<int, int> store;
    int sum = 0;
    int longestLength = 0;
    int start = 0;
    for(int i = 0; i < n; i ++)
    {
        sum += arr[i];
        if(sum == 0) longestLength = i + 1;
        else if(store.find(sum) != store.end())
        {
            int length = i - store[sum];
            if(longestLength < length)
            {
                longestLength = length;
                start = store[sum] + 1;
            }
        }
        else
        {
            store[sum] = i;
        }
    }
    if(longestLength != 0) cout << "Longest sub-array: ";
    else cout << "Longest sub-array does not exist" << endl;
    for(int i = 0; i < longestLength; i ++)
    {
        cout << arr[i + start] << " ";
    }
    cout << endl;
    cout << "Length: " << longestLength << endl;
    return longestLength;
}
int main()
{
    int arr[] = {1,-1,1,-1,1,1,1,11,-1,-1,-1,5,1,1,1,-4,-4,-4,-4,6,6,1,2,3,-5,-2,6,2,10,-6,-6,-3,-1,-1,1,1,1};
    longestSubArrayWithZeroSum(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
