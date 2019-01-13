#include <iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int target)
{
    if(r >= l)
    {
        int mid = l + (r - l) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) return binarySearch(arr, l, mid - 1, target);
        else return binarySearch(arr, mid + 1, r, target);
    }
    return -1;
}
int main()
{
    int arr[] = {1,3,5,7,8};
    cout << binarySearch(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 7);

    return 0;
}
