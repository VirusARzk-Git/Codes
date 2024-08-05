// https://www.codingninjas.com/studio/problems/complete-string_2687860

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

bool insert(TrieNode *root, string key)
{
    bool flag = true;
    TrieNode *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
            curr->child[index] = new TrieNode();
        flag &= curr->isEnd;
        curr = curr->child[index];
    }
    curr->isEnd = true;
    return flag;
}

string completeString(int n, vector<string> &a)
{
    sort(a.begin(), a.end(), [](const string &x, const string &y)
         { if(x.size() < y.size())
                return true;
            if(x.size() > y.size())
                return false;
            return x > y; });

    string ans = "";

    TrieNode *root = new TrieNode();
    root->isEnd = true;
    for (int i = 0; i < n; i++)
    {
        string s = a[i];
        bool f = insert(root, s);
        if (f)
            ans = s;
    }
    if (ans == "")
        ans = "None";
    return ans;
}