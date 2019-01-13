#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;
    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for(int i = n/2-1; i >= 0; i --)
    heapify(arr, n, i);
    for(int i = n - 1; i >= 0; i --)
    {
        swap(arr[0], arr[i]);
        for(int j = i/2-1; j >= 0; j --)
        heapify(arr, i, j);
    }
}
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i ++)
    cout << arr[i] << " ";
}
int main()
{
    int n = 5;
    int arr[n] = {1,4,6,2,7};
    heapSort(arr, n);
    printArray(arr, n);
    return 0;
}
