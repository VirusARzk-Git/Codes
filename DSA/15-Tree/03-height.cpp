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

int height(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->lc), height(root->rc));
}

int main(int argc, char **argv)
{
    Node *root = new Node(10);
    root->lc = new Node(20);
    root->lc->lc = new Node(40);
    root->rc = new Node(30);
    root->rc->rc = new Node(90);
    cout << height(root) << endl;
}