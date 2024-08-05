#include <iostream>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    int idx;
    int len;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        idx = -1;
        len = 1e6;
    }
};

void insert(TrieNode *root, string key, int ind, int leng)
{
    TrieNode *curr = root;
    if (curr->len > leng)
        curr->len = leng, curr->idx = ind;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
            curr->child[index] = new TrieNode();
        curr = curr->child[index];
        if (curr->len > leng)
            curr->len = leng, curr->idx = ind;
    }
}

int search(TrieNode *root, string key)
{
    TrieNode *curr = root;
    int ans = curr->idx;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
            return ans;
        curr = curr->child[index];
        ans = curr->idx;
    }
    return ans;
}

class Solution
{
public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        TrieNode *root = new TrieNode();
        int n = wordsQuery.size();
        int minLenIdx = 0;
        for (int i = 0; i < wordsContainer.size(); i++)
        {
            int len = wordsContainer[i].size();
            if (len < wordsContainer[minLenIdx].size())
                minLenIdx = i;
            string s = wordsContainer[i];
            reverse(s.begin(), s.end());
            insert(root, s, i, len);
        }
        vector<int> ans(n, minLenIdx);
        for (int i = 0; i < wordsQuery.size(); i++)
        {
            string s = wordsQuery[i];
            reverse(s.begin(), s.end());
            ans[i] = search(root, s);
        }
        return ans;
    }
};