#include <iostream>

using namespace std;

void findConflictingMeetings(int start[], int finish[], int n)
{
    // meetings times are sorted based on starting time.
    for(int i = 0; i < n - 1; i ++)
    {
        for(int j = i + 1; j < n; j ++)
        {
            if(finish[i] > start[j])
            {
                cout << start[i] << " " << finish[i] << " and " << start[j] << " " << finish[j] << endl;
            }
        }
    }
}
int main ()
{
    int start[] = {3,4,5,6,7,8,10};
    int finish[] = {5,7,6,10,13,11,12};
    int n = sizeof(finish) / sizeof(finish[0]);
    findConflictingMeetings(start, finish, n);
    return 0;
}
