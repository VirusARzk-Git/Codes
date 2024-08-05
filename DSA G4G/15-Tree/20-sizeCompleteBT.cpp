#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
    int key;
    Node *lc, *rc;
    Node(int k)
    {
        key = k;
        lc = NULL;
        rc = NULL;
    }
};

int sizeOfCompleteBT(Node *root)
{
    int lH = 0, rH = 0;
    Node *curr = root;
    while (curr != NULL)
    {
        lH++;
        curr = curr->lc;
    }
    curr = root;
    while (curr != NULL)
    {
        rH++;
        curr = curr->rc;
    }
    if (lH == rH)
        return pow(2, lH) - 1;
    return 1 + sizeOfCompleteBT(root->lc) + sizeOfCompleteBT(root->rc);
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
    cout << sizeOfCompleteBT(root);
}

//             1
//     2               3
// 4       5       6       7