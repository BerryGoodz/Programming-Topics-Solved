#include <iostream>

//array: {1,2,3,4,5} has no missing numbers
//array: {1,3,4,5} has 1 missing number, 2.
using namespace std;

void findMissingNum(int arr[], int expec, int i, int maxi)
{
    if(expec > maxi) return;
    if(arr[i] != expec)
    {
        cout << "Missing " << expec << endl;
        findMissingNum(arr, expec + 1, i, maxi);
    }
    else
    {
        findMissingNum(arr, expec + 1, i + 1, maxi);
    }
}
int main()
{
    int n = 7;
    int arr[n] = {1,3,4,5,7,10,15};
    findMissingNum(arr, 1, 0, 15);
    return 0;
}
