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

bool isChSum(Node *root)
{
    if (root == NULL)
        return true;
    if (root->lc == NULL && root->rc == NULL)
        return true;
    int s = 0;
    if (root->lc)
        s += root->lc->key;
    if (root->rc)
        s += root->rc->key;
    return (root->key == s && isChSum(root->lc) && isChSum(root->rc));
}

int main(int argc, char **argv)
{
    Node *root = new Node(50);
    root->lc = new Node(20);
    root->lc->lc = new Node(20);
    root->rc = new Node(30);
    root->rc->rc = new Node(30);
    root->rc->rc->lc = new Node(30);
    if (isChSum(root))
        cout << "Followed";
    else
        cout << "Not Followed";
}