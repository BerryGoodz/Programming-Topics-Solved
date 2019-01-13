#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*int lisUtil(int arr[], int n, int base, vector<int> &storage, int current)
{
    int maxItem = 0;
    if(base >= n) return current;
    for(int i = base + 1; i < n; i ++)
    {
        int item = 0;
        if(arr[base] < arr[i])
        {
            item = lisUtil(arr, n, i, storage, current + 1);
        }
        if(maxItem < item) maxItem = item;
    }
    int item = 0;
    item = lisUtil(arr, n, base + 1, storage, current);
    if(item > maxItem) maxItem = item;

    storage.push_back(maxItem);
    return current;
}
int lis(int arr[], int n)
{
    vector<int> storage;
    lisUtil(arr, n, 0, storage, 1);
    int biggest = 0;
    for(int i = 0; i < storage.size(); i ++)
    {
        //cout << storage[i] << endl;
        if(storage[i] > biggest)
            biggest = storage[i];
    }
    return biggest;
}*/
int lis(int arr[], int n)
{
    int table[n];
    for(int i = 0; i < n; i ++)
        table[i] = 1;
    for(int i = 1; i < n; i ++)
    {
        for(int j = 0; j < i; j ++)
        {
            if(arr[i] > arr[j])
            {
                table[i] = max(table[i], table[j] + 1);
            }
        }
    }
    return *max_element(table, table + n);
}
int main ()
{
    int arr[] = {1,2,5,3,2};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << lis(arr, arrSize);
    return 0;
}
