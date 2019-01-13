#include <iostream>
#include <stdio.h>
using namespace std;

//Given number of eggs and floors, find the minimum number of egg drops required to
//find the lowest floor that breaks the egg in a worst case scenario.

//recursive approach
/*
int minEggDrop(int eggs, int floors)
{
    if(floors == 1 || eggs == 0 || floors == 0) return 0;
    if(eggs == 1)
    {
        return floors;
    }
    int answer = INT_MAX;
    for(int i = 1; i <= floors; i ++)
    {
        int worstCase = max(1 + minEggDrop(eggs - 1, i - 1), 1 + minEggDrop(eggs, floors - i));
        if(worstCase < answer)
        {
            answer = worstCase;
        }
    }
    return answer;
}
*/
//dynamic programming
int minEggDrop(int eggs, int floors)
{
    int table[eggs + 1][floors + 1];

    //handle all base cases
    for(int i = 0; i <= eggs; i ++)
    {
        table[i][0] = 0;
        table[i][1] = 0;
    }
    for(int i = 1; i <= floors; i ++)
    {
        table[0][i] = 0;
        table[1][i] = i;
    }

    //bottom-up approach to build the table
    for(int i = 2; i <= eggs; i ++)
    {
        for(int j = 2; j <= floors; j ++)
        {
            table[i][j] = INT_MAX;
            for(int k = 1; k <= j; k ++)
            {
                int worstCase = max(1 + table[i - 1][k - 1], 1 + table[i][j - k]);
                if(worstCase < table[i][j])
                {
                    table[i][j] = worstCase;
                }
            }
        }
    }
    /*for(int i = 0; i <= eggs; i ++)
    {
        for(int j = 0; j <= floors; j ++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }*/
    return table[eggs][floors];
}
int main ()
{
    int n = 2;
    int k = 10;
    printf("Minimum egg drops required with %d eggs and %d floors is %d", n, k, minEggDrop(n, k));
    return 0;
}
