#include <iostream>

using namespace std;

/*
    Find the minimum jumps to reach from index 0 to the last index of the array.
    The values in the array indicate the maximum possible jumps.
    For example, the minimum jump of the array:
    {2,4,1,3,2,2,1} is 3
    2 -> 4 -> 2 -> 1

*/
int minimumJumps(int arr[], int n, int jump, int startPoint, int minJump)
{
    if(startPoint + jump >= n - 1) return minJump;
    int bestJump = 0;
    int bestJumpIndex = 0;
    for(int i = 1; i <= jump; i ++)
    {
        int current_jump = arr[i + startPoint] + i;
        if(current_jump > bestJump)
        {
            bestJump = current_jump;
            bestJumpIndex = startPoint + i;
        }
    }
    if(bestJumpIndex == 0) return -1;
    return minimumJumps(arr, n, arr[bestJumpIndex], bestJumpIndex, minJump + 1);
}
int main()
{
    int arr[] = {3,2,1,2,2,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minimumJumps(arr, n, arr[0], 0, 1);
    return 0;
}
