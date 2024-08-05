#include <iostream>
#include <algorithm>
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

int height(Node *root, int &diameter)
{
    if (!root)
        return 0;
    int lH = height(root->lc, diameter);
    int rH = height(root->rc, diameter);
    diameter = max(diameter, 1 + lH + rH);
    return 1 + max(lH, rH);
}

int main(int argc, char **argv)
{
    int diameter = 0;
    Node *root = new Node(20);
    root->lc = new Node(10);
    root->lc->lc = new Node(5);
    root->lc->rc = new Node(15);
    root->rc = new Node(45);
    root->rc->rc = new Node(90);
    root->rc->lc = new Node(30);
    height(root, diameter);
    cout << diameter;
}