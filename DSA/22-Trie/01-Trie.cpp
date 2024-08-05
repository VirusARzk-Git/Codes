#include <iostream>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

bool search(TrieNode *root, string key)
{
    TrieNode *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
            return false;
        curr = curr->child[index];
    }
    return curr->isEnd;
}

void insert(TrieNode *root, string key)
{
    TrieNode *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
            curr->child[index] = new TrieNode();
        curr = curr->child[index];
    }
    curr->isEnd = true;
}

bool isEmpty(TrieNode *root)
{
    for (int i = 0; i < 26; i++)
        if (root->child[i] != NULL)
            return false;
    return true;
}

TrieNode *delKey(TrieNode *root, string key, int i = 0)
{
    if (root == NULL)
        return NULL;
    if (i == key.length())
    {
        root->isEnd = false;
        if (isEmpty(root))
        {
            delete (root);
            root = NULL;
        }
        return root;
    }

    int index = key[i] - 'a';
    root->child[index] = delKey(root->child[index], key, i + 1);
    if (isEmpty(root) && root->isEnd == false)
    {
        delete (root);
        root = NULL;
    }
    return root;
}

int main()
{
    TrieNode *root = new TrieNode();
    insert(root, "aditya");
    cout << search(root, "aditya");
    delKey(root, "aditya");
    cout << search(root, "aditya");
}