#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

void serialize(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->key);
    serialize(root->left, arr);
    serialize(root->right, arr);
}

Node *deserialize(vector<int> &arr, int &idx)
{
    if (idx == arr.size())
        return NULL;
    int val = arr[idx++];
    if (val == -1)
        return NULL;
    Node *root = new Node(val);
    root->left = deserialize(arr, idx);
    root->right = deserialize(arr, idx);
    return root;
}

// Create tree from given Level Order Traversal

int left(int i) { return (2 * i + 1); }
int right(int i) { return (2 * i + 2); }

Node *deserialize(vector<int> arr, int i = 0)
{
    if (i >= arr.size() || arr[i] == -1)
        return NULL;
    Node *t = new Node(arr[i]);
    t->left = deserialize(arr, left(i));
    t->right = deserialize(arr, right(i));
    return t;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans;
    serialize(root, ans);
    for (int i : ans)
        cout << i << ' ';
    cout << endl;
    int i = 0;
    Node *root2 = deserialize(ans, i);
    ans.clear();
    serialize(root2, ans);
    for (int i : ans)
        cout << i << ' ';
}

//             1
//     2               3
// 4       5       6       7