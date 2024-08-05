#include <iostream>
#include <vector>
using namespace std;

struct TrieNode
{
    TrieNode *child[2];
    TrieNode()
    {
        child[0] = child[1] = NULL;
    }
};

bool insert(TrieNode *root, vector<vector<int>> mat, int row)
{
    TrieNode *curr = root;
    int flag = false;
    for (int i = 0; i < mat[row].size(); i++)
    {
        bool index = mat[row][i];
        if (curr->child[index] == NULL)
        {
            curr->child[index] = new TrieNode();
            flag = true;
        }
        curr = curr->child[index];
    }
    return flag;
}

int countDistinct(vector<vector<int>> mat)
{
    TrieNode *root = new TrieNode();
    int ans = 0;
    for (int i = 0; i < mat.size(); i++)
        if (insert(root, mat, i))
            ans++;
    return ans;
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];
    cout << countDistinct(mat);
}