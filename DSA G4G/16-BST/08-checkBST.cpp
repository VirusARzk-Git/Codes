#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int key;
    Node *lc, *rc;
    Node(int c)
    {
        key = c;
        lc = rc = NULL;
    }
};

bool isBST(Node *root, long min = LONG_MIN, long max = LONG_MAX)
{
    if (root == NULL)
        return true;
    return (root->key > min && root->key < max && isBST(root->lc, min, root->key) && isBST(root->rc, root->key, max));
}

int main()
{
    Node *root = new Node(15);
    root->lc = new Node(5);
    root->lc->lc = new Node(3);
    root->rc = new Node(20);
    root->rc->lc = new Node(18);
    root->rc->lc->lc = new Node(16);
    root->rc->rc = new Node(80);
    cout << isBST(root);
}