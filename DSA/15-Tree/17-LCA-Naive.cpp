#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int key;
    Node *lc;
    Node *rc;

    Node(int k)
    {
        key = k;
        lc = NULL;
        rc = NULL;
    }
};

bool findPath(Node *root, vector<Node *> &p, int n)
{
    if (root == NULL)
        return false;
    p.push_back(root);
    if (root->key == n)
        return true;
    if (findPath(root->lc, p, n) || findPath(root->rc, p, n))
        return true;
    p.pop_back();
    return false;
}

// LCA  - Lowest Common Ancestor
Node *LCA_Naive(Node *root, int n1, int n2)
{
    vector<Node *> p1, p2;
    if (findPath(root, p1, n1) == false || findPath(root, p2, n2) == false)
        return NULL;
    for (int i = 1; i < max(p1.size(), p2.size()); i++)
        if (p1[i] != p2[i])
            return p1[i - 1];
    return NULL;
}

int main(int argc, char **argv)
{
    Node *root = new Node(1);
    root->lc = new Node(2);
    root->rc = new Node(3);
    root->lc->lc = new Node(4);
    root->lc->rc = new Node(5);
    root->rc->lc = new Node(6);
    root->rc->rc = new Node(7);
    cout << "LCA(4, 5) = " << LCA_Naive(root, 4, 5)->key;
    cout << "\nLCA(4, 6) = " << LCA_Naive(root, 4, 6)->key;
    cout << "\nLCA(3, 4) = " << LCA_Naive(root, 3, 4)->key;
    cout << "\nLCA(2, 4) = " << LCA_Naive(root, 2, 4)->key;
}