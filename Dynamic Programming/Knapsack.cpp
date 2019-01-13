#include <iostream>

using namespace std;

//given int arrays of values and weights, find biggest value obtainable while not exceeding the weight limit. Same item cannot be used twice.
/*int knap(int val[], int wei[], int totalW, int n)
{
    if(totalW == 0) return 0;
    if(n <= 0) return 0;
    if(wei[n - 1] > totalW) return knap(val, wei, totalW, n - 1);
    return max(val[n - 1] + knap(val, wei, totalW - wei[n - 1], n - 1), knap(val, wei, totalW, n - 1));
}*/
int knap(int val[], int wei[], int totalW, int n)
{
    int table[n + 1][totalW + 1];
    for(int i = 0; i <= n; i ++)
    {
        for(int w = 0; w <= totalW; w ++)
        {
            if(w == 0 || i == 0) table[i][w] = 0;
            else if(wei[i - 1] <= w)
            {
                table[i][w] = max(val[i - 1] + table[i - 1][w - wei[i - 1]], table[i - 1][w]);
            }
            else table[i][w] = table[i - 1][w];
        }
    }
    for(int i = 0; i <= n; i ++)
    {
        for(int w = 0; w <= totalW; w ++)
        {
            cout << table[i][w] << " ";
        }
        cout << endl;
    }
    return table[n][totalW];
}
int main ()
{
    int val[] = {2,5,6,8,10,12,15};
    int wei[] = {1,2,3,4,5,6,7};
    knap(val, wei, 20, 7);
    return 0;
}
