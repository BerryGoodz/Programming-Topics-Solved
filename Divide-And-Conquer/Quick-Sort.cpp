#include <iostream>

using namespace std;

int partit(int arr[], int low, int high)
{
    int pivot = arr[high];
    int lowIndex = low;
    for(int i = low; i < high; i ++)
    {
        if(pivot >= arr[i])
        {
            swap(arr[i], arr[lowIndex]);
            lowIndex ++;
        }
    }
    swap(arr[lowIndex], arr[high]);
    return lowIndex;
}
void quickSortUtil(int arr[], int low, int high)
{
    if(low == high || low > high) return;
    int pivot = partit(arr, low, high);
    quickSortUtil(arr, low, pivot - 1);
    quickSortUtil(arr, pivot + 1, high);
}
void quickSort(int arr[], int n)
{
    quickSortUtil(arr, 0, n - 1);
}
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i ++)
    {
        cout << arr[i] << " ";
    }
}
int main ()
{
    int arr[] = {4,4,2,-2,-1,0,5,299,502,1,3,87,300,2,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, n);
    printArray(arr, n);
    return 0;
}
