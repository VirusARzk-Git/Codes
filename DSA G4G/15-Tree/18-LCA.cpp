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

// LCA  - Lowest Common Ancestor
Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->key == n1 || root->key == n2)
        return root;
    Node *lca1 = LCA(root->lc, n1, n2);
    Node *lca2 = LCA(root->rc, n1, n2);
    if (lca1 != NULL && lca2 != NULL)
        return root;
    if (lca1 != NULL)
        return lca1;
    return lca2;
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
    cout << "LCA(4, 5) = " << LCA(root, 4, 5)->key;
    cout << "\nLCA(4, 6) = " << LCA(root, 4, 6)->key;
    cout << "\nLCA(3, 4) = " << LCA(root, 3, 4)->key;
    cout << "\nLCA(2, 4) = " << LCA(root, 2, 4)->key;
}