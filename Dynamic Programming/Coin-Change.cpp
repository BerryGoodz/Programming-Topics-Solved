include <iostream>

using namespace std;

// In how many ways can you get a change of a certain amount of money?

//recursion
/*int coinChange(int arr[], int k, int n)
{
    if(n < 0) return 0;
    if(k < 0) return 0;
    if(k == 0) return 1;
    return coinChange(arr, k - arr[n], n) + coinChange(arr, k, n - 1);
}*/
//tabulation
int coinChange(int arr[], int k, int n)
{
    int table[n + 1][k + 1];

    for(int i = 0; i <= n; i ++)
        table[i][0] = 1;
    for(int i = 0; i <= k; i ++)
        table[0][i] = 0;

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= k; j ++)
        {
            if(j >= arr[i - 1])
            {
                table[i][j] = table[i][j - arr[i - 1]] + table[i - 1][j];
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    for(int i = 0; i <= n; i ++)
    {
        for(int j = 0; j <= k; j ++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    return table[n][k];
}
int main ()
{
    // program that computes the number of ways to get a change of a dollar
    //int arr[] = {1, 5, 10, 25};
    int arr[] = {2,3,4,5,6,7,8};
    coinChange(arr, 10, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
