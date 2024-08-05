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

int isBalanced(Node *root)
{
    if (!root)
        return 0;
    int lH = isBalanced(root->lc);
    if (lH == -1)
        return -1;
    int rH = isBalanced(root->rc);
    if (rH == -1)
        return -1;
    if (abs(lH - rH) > 1)
        return -1;
    return max(lH, rH) + 1;
}

int main(int argc, char **argv)
{
    Node *root = new Node(20);
    root->lc = new Node(10);
    root->lc->lc = new Node(5);
    root->lc->rc = new Node(15);
    root->rc = new Node(45);
    root->rc->rc = new Node(90);
    root->rc->lc = new Node(30);
    if (isBalanced(root) >= 0)
        cout << "Balanced";
    else
        cout << "Not Balanced";
}