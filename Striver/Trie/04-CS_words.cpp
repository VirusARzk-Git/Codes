// https://www.codingninjas.com/studio/problems/implement-trie_1387095

#include <bits/stdc++.h>

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;
    int preCount;
    int endCount;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        preCount = 0;
        endCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *curr = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (curr->children[idx] == NULL)
                curr->children[idx] = new TrieNode();
            curr->preCount++;
            curr = curr->children[idx];
        }
        curr->isEnd = true;
        curr->preCount++;
        curr->endCount++;
    }

    int countWordsEqualTo(string &word)
    {
        TrieNode *curr = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (curr->children[idx] == NULL)
                return 0;
            curr = curr->children[idx];
        }
        return curr->endCount;
    }

    int countWordsStartingWith(string &word)
    {
        TrieNode *curr = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (curr->children[idx] == NULL)
                return 0;
            curr = curr->children[idx];
        }
        return curr->preCount;
    }

    void erase(string &word)
    {
        TrieNode *curr = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (curr->children[idx] == NULL)
                return;
            curr->preCount--;
            curr = curr->children[idx];
        }
        curr->preCount--;
        curr->endCount--;
    }
};
