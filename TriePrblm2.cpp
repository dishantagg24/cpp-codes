//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Maximum Xor of two numbers from two array (we can take whole array)
// Time Complexity:- O(n*32) + O(m*32)
// n,m are sizes of two array
struct Node
{
    Node *links[2];

    bool checkNode(int bit)
    {
        return links[bit] != NULL;
    }
    Node *getNode(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!temp->checkNode(bit))
            {
                temp->put(bit, new Node());
            }
            temp = temp->getNode(bit);
        }
    }
    int getMax(int x)
    {
        Node *temp = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            if (temp->checkNode(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                temp = temp->getNode(1 - bit);
            }
            else
            {

                temp = temp->getNode(bit);
            }
        }
        return maxNum;
    }
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        trie.insert(arr1[i]);
    }
    int maxi = 0;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, trie.getMax(arr2[i]));
    }
    return maxi;
}

//*Maximum XOR With an Element From Array but we can not take the whole array
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> ans(queries.size(), 0);
    vector<pair<int, pair<int, int>>> offlineQueries;
    sort(arr.begin(), arr.end());
    int index = 0;
    for (auto &it : queries)
    {
        offlineQueries.push_back({it[1], {it[0], index++}});
    }
    sort(offlineQueries.begin(), offlineQueries.end());
    int i = 0;
    int n = arr.size();
    Trie trie;

    for (auto &it : offlineQueries)
    {
        while (i < n && arr[i] <= it.first)
        {
            trie.insert(arr[i]);
            i++;
        }
        if (i != 0)
            ans[it.second.second] = trie.getMax(it.second.first);
        else
            ans[it.second.second] = -1;
    }
    return ans;
}
int main()
{
    vector<int> arr1 = {6, 8};
    vector<int> arr2 = {7, 8, 2};
    int n = 2, m = 3;
    cout << maxXOR(n, m, arr1, arr2) << endl;
    return 0;
}