#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int leftN = m - l + 1;
    int rightN = r - m;
    int arrLeft[leftN];
    int arrRight[rightN];
    for(int i = l; i< leftN + l; i ++)
        arrLeft[i] = arr[i];
    for(int i = m; i < rightN + m; i ++)
        arrRight[i] = arr[i + 1];
    int i = 0;
    int j = 0;
    int k = l;
    while(i < leftN && j < rightN)
    {
        if(arrLeft[i] > arrRight[j])
        {
            arr[k] = arrRight[j];
            k ++;
            j ++;
        }
        else
        {
            arr[k] = arrLeft[i];
            i ++;
            k ++;
        }
    }
    while(i < leftN)
    {
        arr[k] = arrLeft[i];
        k++;
        i ++;
    }
    while(j < rightN)
    {
        arr[k] = arrRight[j];
        k++;
        j ++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (r - l) / 2 + l;
        mergeSort(arr, m + 1, r);
        mergeSort(arr, l, m);
        merge(arr, l, m, r);
    }
}
