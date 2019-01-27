#include <iostream>

using namespace std;

bool subArrayWithSum(int arr[], int n, int sum)
{
    int current_sum = 0;
    int low = 0;
    int high;
    for(high = 0; high < n; high ++)
    {
        current_sum += arr[high];
        if(current_sum > sum)
        {
            current_sum -= arr[low];
            low ++;
        }
        if(current_sum == sum)
        {
            cout << "Sub-array found from " << low << " to " << high;
            return true;
        }
    }
    cout << "Sub-array not found.";
    return false;
}
int main ()
{
    int arr[] = {4,2,6,7,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    subArrayWithSum(arr, n, -13);
    return 0;
}
