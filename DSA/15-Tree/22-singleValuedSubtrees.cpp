// Given a Level Order Traversal of a binary tree,
// write a program to count the number of Single Valued Subtrees.
// A Single Valued Subtree is one in which all the nodes have same value.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int k)
    {
        data = k;
        left = NULL;
        right = NULL;
    }
};

int left(int i) { return (2 * i + 1); }
int right(int i) { return (2 * i + 2); }

bool countSingleRec(Node *root, int &count)
{
    if (root == NULL)
        return true;

    bool left = countSingleRec(root->left, count);
    bool right = countSingleRec(root->right, count);

    if (left == false || right == false)
        return false;

    if (root->left && root->data != root->left->data)
        return false;

    if (root->right && root->data != root->right->data)
        return false;

    count++;
    return true;
}

int countSingle(Node *root)
{
    int count = 0;
    countSingleRec(root, count);
    return count;
}

Node *deserialize(vector<int> arr, int i = 0)
{
    if (i >= arr.size() || arr[i] == -1)
        return NULL;
    Node *t = new Node(arr[i]);
    t->left = deserialize(arr, left(i));
    t->right = deserialize(arr, right(i));
    return t;
}

int code()
{
    int n;
    cin >> n;

    if (n == -1)
        return -1;

    if (n == 0)
        return 1;

    vector<int> v;
    int e;
    while (cin >> e)
        v.push_back(e);
    Node *root = deserialize(v);
    return countSingle(root);
}

signed main()
{
    cout << code();
    return 0;
}