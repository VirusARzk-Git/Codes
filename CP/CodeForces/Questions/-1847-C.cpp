struct TrieNode
{
    TrieNode children[2];
    TrieNode()
    {
        children[0] = children[1] = nullptr;
    }
};

void insert(TrieNoderoot, int num)
{
    TrieNode curr = root;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        if (curr->children[bit] == nullptr)
        {
            curr->children[bit] = new TrieNode();
        }
        curr = curr->children[bit];
    }
}

int findMaxXOR(TrieNoderoot, int num)
{
    TrieNode curr = root;
    int maxXOR = 0;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        int oppositeBit = bit ^ 1;
        if (curr->children[oppositeBit] != nullptr)
        {
            maxXOR |= (1 << i);
            curr = curr->children[oppositeBit];
        }
        else
        {
            curr = curr->children[bit];
        }
    }
    return maxXOR;
}

int findMaxXORofSubarrays(vector<int> &nums)
{
    TrieNoderoot = new TrieNode();
    insert(root, 0);
    int maxXOR = 0;
    int currXOR = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currXOR ^= nums[i];
        insert(root, currXOR);
        maxXOR = max(maxXOR, findMaxXOR(root, currXOR));
    }
    return maxXOR;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        int maxSubarrayXOR = findMaxXORofSubarrays(nums);
        cout << maxSubarrayXOR << endl;
    }

    return 0;
}