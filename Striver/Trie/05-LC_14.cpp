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

class Trie
{
public:
    TrieNode *root;
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
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &arr)
    {
        Trie trie;
        for (string &s : arr)
            trie.insert(s);

        string lcp = "";
        TrieNode *curr = trie.root;
        while (!curr->isEnd)
        {
            int count = 0;
            int idx = -1;
            for (int i = 0; i < 26; i++)
            {
                if (curr->children[i] != NULL)
                {
                    count++;
                    idx = i;
                }
            }
            if (count != 1)
                break;
            lcp += (char)(idx + 'a');
            curr = curr->children[idx];
        }
        return lcp;
    }
};