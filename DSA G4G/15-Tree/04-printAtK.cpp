#include <iostream>
#include <queue>
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

void printAtK(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
        cout << root->key << ' ';
    else
    {
        printAtK(root->lc, k - 1);
        printAtK(root->rc, k - 1);
    }
}

int main()
{
    Node *root = new Node(10);
    root->lc = new Node(20);
    root->lc->lc = new Node(40);
    root->rc = new Node(30);
    root->rc->rc = new Node(90);
    printAtK(root, 2);
}