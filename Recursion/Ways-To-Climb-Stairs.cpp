#include <iostream>

using namespace std;

int num_ways(int num_of_stairs, int steps_so_far, int solution)
{
    if(steps_so_far == num_of_stairs) return 1;
    else if(steps_so_far > num_of_stairs) return 0;
    return num_ways(num_of_stairs, steps_so_far + 1, solution) + num_ways(num_of_stairs, steps_so_far + 2, solution);
}
int main()
{
    cout << num_ways(3, 0, 0);
    return 0;
}
