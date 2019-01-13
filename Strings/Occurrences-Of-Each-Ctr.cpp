#include <iostream>
#include <unordered_map>

using namespace std;

/*
    "cheese" should print
    c - 1
    h - 1
    e - 3
    s - 1
*/
void countOccurencesOfEachCtr(string s)
{
    unordered_map<char, int> store;

    for(int i = 0; i < s.size(); i ++)
    {
        if(store.find(s[i]) != store.end())
        {
            store[s[i]] += 1;
        }
        else
        {
            store[s[i]] = 1;
        }
    }
    for(auto it : store)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}
int main()
{
    string s = "cheese";
    countOccurencesOfEachCtr(s);
    return 0;
}
