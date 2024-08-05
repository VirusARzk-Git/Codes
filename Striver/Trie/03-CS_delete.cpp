// https://www.codingninjas.com/studio/problems/trie-delete-operation_1062663

#include <bits/stdc++.h>

/*
class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};
*/

TrieNode *solution::deleteWord(TrieNode *root, string word)
{
    TrieNode *node = root;
    for (char ch : word)
    {
        int idx = ch - 'a';
        if (node->children[idx] == NULL)
            return root;
        node = node->children[idx];
    }
    node->isEnd = false;
}