#include <iostream>

using namespace std;

int subSetSum(int arr[], int s, int sum)
{
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(s == 0) return 0;
    return max(subSetSum(arr, s - 1, sum - arr[s - 1]), subSetSum(arr, s - 1, sum));
}
int subSetSumDP(int arr[], int s, int sum)
{
    int table[sum + 1][s];
    for(int i = 0; i < s; i ++)
    {
        table[0][i] = 1;
    }
    for(int i = 1; i < sum + 1; i ++)
    {
        for(int j = 0; j < s; j ++)
        {
            int x, y;
            if(i - arr[j] == 0)
            {
                x = 1;
            }
            else if(i - arr[j] > 0 && j - 1 >= 0)
            {
                x = table[i - arr[j]][j - 1];
            }
            else
            {
                x = 0;
            }
            if(j - 1 >= 0)
            {
                y = table[i][j - 1];
            }
            else
            {
                y = 0;
            }
            table[i][j] = max(x, y);
        }
    }
    for(int i = 0; i < sum + 1; i ++)
    {
        for(int j = 0; j < s; j ++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    return table[sum][s - 1];
}
int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 10;
    int s = sizeof(arr)/sizeof(arr[0]);
    subSetSumDP(arr, s, sum);
    return 0;
}
/*


*/
