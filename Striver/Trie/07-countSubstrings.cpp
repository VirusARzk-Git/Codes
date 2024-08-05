// https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292

#include <bits/stdc++.h>

struct TrieNode
{
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        isEnd = false;
    }
};

void insert(TrieNode *root, string key, int &ans)
{
    TrieNode *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
        {
            curr->child[index] = new TrieNode();
            ans++;
        }
        curr = curr->child[index];
    }
    curr->isEnd = true;
}

int countDistinctSubstrings(string &s)
{
    TrieNode *root = new TrieNode();
    int n = s.size(), ans = 1;
    for (int i = 0; i < n; i++)
    {
        string str = s.substr(i);
        insert(root, str, ans);
    }
    return ans;
}