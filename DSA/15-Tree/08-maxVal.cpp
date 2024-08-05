#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
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

int maxVal(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    return max({root->key, maxVal(root->lc), maxVal(root->rc)});
}

int main(int argc, char **argv)
{
    Node *root = new Node(10);
    root->lc = new Node(20);
    root->lc->lc = new Node(1);
    root->rc = new Node(5);
    root->rc->rc = new Node(15);
    cout << maxVal(root) << endl;
}