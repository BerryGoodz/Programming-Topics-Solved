#include <iostream>

using namespace std;

int knapsack(int value[], int weight[], int n, int maximum)
{
    if(maximum < 0) return -10000;
    if(n == 0 || maximum == 0) return 0;
    int include = value[n - 1] + knapsack(value, weight, n - 1, maximum - weight[n - 1]);
    int exclude = knapsack(value, weight, n - 1, maximum);
    return max(include, exclude);
}
int main ()
{
    int value[] = {3, 5,2,4,2,2,1, 1, 3};
    int weight[] = {20, 15, 10, 15,30,20,15,15,30}; // weight limit: 30
    cout << knapsack(value, weight, 4, 60);
    return 0;
}
