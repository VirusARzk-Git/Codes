#include <iostream>
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

bool search(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->key == x)
        return true;
    if (root->key > x)
        return search(root->lc, x);
    return search(root->rc, x);
}

bool iterativeSearch(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->key == x)
            return true;
        else if (root->key < x)
            root = root->rc;
        else
            root = root->lc;
    }
    return false;
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
}