#include <iostream>
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

int res = 0;
int burnTime(Node *root, int leaf, int &dist)
{
    if (root == NULL)
        return 0;
    if (root->key == leaf)
    {
        dist = 0;
        return 1;
    }
    int lDist = -1, rDist = -1;
    int lH = burnTime(root->lc, leaf, lDist);
    int rH = burnTime(root->rc, leaf, rDist);
    if (lDist != -1)
    {
        dist = lDist + 1;
        res = max(res, dist + rH);
    }
    else if (rDist != -1)
    {
        dist = rDist + 1;
        res = max(res, dist + lH);
    }
    return max(lH, rH) + 1;
}

int main()
{
    Node *root = new Node(1);
    root->lc = new Node(2);
    root->rc = new Node(3);
    root->lc->lc = new Node(4);
    root->lc->rc = new Node(5);
    root->rc->lc = new Node(6);
    root->rc->rc = new Node(7);
    int d = 0;
    burnTime(root, 7, d);
    cout << res;
}

//             1
//     2               3
// 4       5       6       7