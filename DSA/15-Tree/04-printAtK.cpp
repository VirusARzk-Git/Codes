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

class Solution
{
    vector<int> ans;
    int k;
    void f(Node *root, int level)
    {
        if (!root)
            return;
        if (k == level)
        {
            ans.push_back(root->data);
            return;
        }
        f(root->left, level + 1);
        f(root->right, level + 1);
    }

public:
    vector<int> Kdistance(struct Node *root, int k_)
    {
        k = k_;
        f(root, 0);
        return ans;
    }
};

void printAtK(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
        cout << root->data << ' ';
    else
    {
        printAtK(root->left, k - 1);
        printAtK(root->right, k - 1);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->right = new Node(30);
    root->right->right = new Node(90);
    printAtK(root, 2);
}