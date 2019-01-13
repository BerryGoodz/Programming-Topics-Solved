#include <iostream>

using namespace std;

//Select most activities possible with its start and finish time. Only one activity can be performed at a time.

int activitySelection(int start[], int finish[], int n)
{
    int answer = 1;

    // we assume that the activities are sorted in the order of finish time.
    // iteration starts from 1, not 0 because first activity is always selected.
    int lastFinishedTime = finish[0];
    for(int i = 1; i < n; i ++)
    {
        if(lastFinishedTime <= start[i])
        {
            answer ++;
            lastFinishedTime = finish[i];
        }
    }
    return answer;
}
int main ()
{
    int start[] = {10, 12, 20};
    int finish[] = {20, 25, 30};
    int n = sizeof(start)/sizeof(start[0]);
    cout << activitySelection(start, finish, n);
    return 0;
}
