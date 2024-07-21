#include <bits/stdc++.h>
using namespace std;



const int INF = 1e9;

class Node
{
public:
    Node *arr[26];
    bool end;
    int val;

    Node()
    {
        memset(arr, NULL, sizeof(arr));
        end = 0;
        val = 0;
    }
};

class Trie
{

public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(string word, int val)
    {
        Node *curr = root;
        for (char c : word)
        {
            int pos = c - 'a';
            if (curr->arr[pos] == NULL)
                curr->arr[pos] = new Node();
            curr = curr->arr[pos];
        }

        if (curr->end)
            curr->val = min(curr->val, val);
        else
        {
            curr->end = true;
            curr->val = val;
        }
    }

    int getMinCost(int ind, Node *curr, string &s)
    {
        if (curr == NULL)
            return INF;
        int n = s.length();
        if (ind == n && curr == root)
            return 0;

        if (ind == n && curr != root)
            return INF;
        
        int val = INF;

        curr = curr->arr[s[ind] - 'a'];

        if (curr == NULL)
            return INF;

        if (curr->end)
            val = min(val, curr->val + getMinCost(ind + 1, root, s));
        else 
            val = min(val, getMinCost(ind + 1, curr, s));
        return val;
    }
};

class Solution
{
public:
    int minimumCost(string target, vector<string> &words, vector<int> &costs)
    {
        Trie trie;
        int n = words.size();

        for (int i=0; i<n; i++)
        {
            trie.insert(words[i], costs[i]);
        }

        return trie.getMinCost(0, trie.root, target);
    }
};

int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (nums[i] != -1)
            mp[nums[i]] += i;
    }
    int maxi = INT_MIN;
    int res = 0;
    for (auto i : mp)
    {
        if (maxi < i.second)
        {
            maxi = i.second;
            res = i.first;
        }
    }
    cout << res;
}