// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie
{
    class TrieNode
    {
    public:
        bool isEnd;
        TrieNode *children[26];
        TrieNode()
        {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode *root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word)
    {
        TrieNode *curr = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (curr->children[idx] == NULL)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *curr = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (curr->children[idx] == NULL)
                return false;
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (char ch : prefix)
        {
            int idx = ch - 'a';
            if (curr->children[idx] == NULL)
                return false;
            curr = curr->children[idx];
        }
        return true;
    }
};