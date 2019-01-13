#include <iostream>

using namespace std;

//the numbers in the array represent number of steps you can jump to the right. Find minimum jumps required to reach the end of the array.
int numberOfJumps(int arr[], int n, int jump)
{
    if(n == 0 || arr[jump] == 0) return 0;
    if(jump + arr[jump] >= n - 1)
    {
        cout << arr[n - 1] << endl;
        return 1;
    }
    int iEnd = arr[jump] + jump;
    int bestJump = 0;
    int ibest = iEnd;
    for(int i = jump + 1; i < iEnd; i ++)
    {
        if(bestJump < arr[i] - iEnd + i)
        {
            bestJump = arr[i];
            ibest = jump + i;
        }
    }
    cout << arr[ibest] << " -> ";
    return 1 + numberOfJumps(arr, n, ibest);
}
void numberOfJumpsUtil(int arr[], int n)
{
    if(arr[0] != 0) cout << arr[0] << " -> ";
    int answer = numberOfJumps(arr, n, 0);
    cout << "Answer is " << answer;
}
int main ()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    numberOfJumpsUtil(arr, arrSize);
    return 0;
}
