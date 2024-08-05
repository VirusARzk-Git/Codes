

struct TrieNode
{
    TrieNode *child[2];
    TrieNode()
    {
        child[0] = child[1] = NULL;
    }
};

int search(TrieNode *root, int key)
{
    int ans = 0, k = key;
    TrieNode *curr = root;
    for (int i = 31; i >= 0; i--)
    {
        int index = (key >> i) & 1;
        if (curr->child[1 - index] != NULL)
        {
            ans += ((1 - index) << i);
            curr = curr->child[1 - index];
        }
        else if (curr->child[index] != NULL)
        {
            ans += ((index) << i);
            curr = curr->child[index];
        }
        else
            break;
    }
    return ans ^ k;
}

void insert(TrieNode *root, int key)
{
    TrieNode *curr = root;
    for (int i = 31; i >= 0; i--)
    {
        int index = (key >> i) & 1;
        if (curr->child[index] == NULL)
            curr->child[index] = new TrieNode();
        curr = curr->child[index];
    }
}

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        TrieNode *root = new TrieNode();
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            insert(root, nums[i]);
            ans = max(ans, search(root, nums[i]));
        }
        return ans;
    }
};