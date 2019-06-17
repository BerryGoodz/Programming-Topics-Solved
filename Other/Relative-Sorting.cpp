#include <iostream>
#include <algorithm>
using namespace std;

void relativeSort(int arr1[], int n1, int arr2[], int n2)
{
    int low = 0;
    for(int i = 0; i < n1; i ++)
    {
        for(int j = low; j < n2; j ++)
        {
            if(arr2[j] == arr1[i])
            {
                swap(arr2[j], arr2[low]);
                if(low < n2 - 1) low ++;
            }
        }
    }
    int endArrSize = n2 - low;
    if(endArrSize > 0)
    {
        int endArr[endArrSize];
        for(int i = 0; i < endArrSize; i ++)
        {
            endArr[i] = arr2[i + low];
        }
        sort(endArr, endArr + endArrSize);
        for(int i = 0; i < endArrSize; i ++)
        {
            arr2[i + low] = endArr[i];
        }
    }


}
void print(int arr[], int n)
{
    for(int i = 0; i < n; i ++)
    {
        cout << arr[i] << " ";
    }cout << endl;
}
int main()
{
    int arr1[] = {4, 2, 6, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {3, 2, 6, 5, 6, 4, 1, 1, 4, 2, 6, 3, 8, 12, 9, 0, 5, 19, 3, 16};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    print(arr2, n2);
    relativeSort(arr1, n1, arr2, n2);
    print(arr2, n2);


    return 0;
}
