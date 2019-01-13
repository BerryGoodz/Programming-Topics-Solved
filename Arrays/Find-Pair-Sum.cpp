#include <iostream>
#include <unordered_set>
using namespace std;

bool isTherePairSum(int arr[], int n, int target)
{
    unordered_set<int> lookUp;
    for(int i = 0; i < n; i ++)
    {
        if(lookUp.find(arr[i]) != lookUp.end())
        {
            return true;
        }
        else
        {
            lookUp.insert(target - arr[i]);
        }
    }
    return false;
}
int main()
{
    int arr[4] = {4,2,1,6};
    cout << isTherePairSum(arr, 4, 3);
    return 0;
}
