#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
Node* newNode(int data)
{
    Node *node = new Node;
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}
void setVerticalOrderMap(Node *root, unordered_map<int, vector<int>> &myMap, int order)
{
    if(root != NULL)
    {

        unordered_map<int, vector<int>>::const_iterator got = myMap.find(order);
        if(myMap.end() == got)
        {
            vector<int> temp;
            pair<int, vector<int>> myPair(order, temp);
            myMap.insert(myPair);
        }
        myMap.at(order).push_back(root -> data);
        setVerticalOrderMap(root -> left, myMap, order - 1);
        setVerticalOrderMap(root -> right, myMap, order + 1);
    }
}
void printVerticalOrder(const unordered_map<int, vector<int>> &myMap)
{
    int mapSize = myMap.size();
    int orderArr[mapSize];
    int index = 0;
    for(auto it = myMap.begin(); it != myMap.end(); ++it)
    {
        orderArr[index] = it -> first;
        index ++;
    }
    int n = sizeof(orderArr) / sizeof(orderArr[0]);
    sort(orderArr, orderArr + n);
    for(int i = 0; i < mapSize; i ++)
    {
        unordered_map<int, vector<int>>::const_iterator got = myMap.find(orderArr[i]);
        vector<int> temp = got -> second;
        for(int i = 0; i < temp.size(); i ++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    unordered_map<int, vector<int>> myMap; // if ordered map was used, there is no need to sort in the function 'printVerticalOrder'
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    setVerticalOrderMap(root, myMap, 0);
    printVerticalOrder(myMap);
    return 0;
}
