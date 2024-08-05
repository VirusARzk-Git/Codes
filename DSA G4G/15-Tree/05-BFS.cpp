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

void BFS(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->key << ' ';
        if (curr->lc != NULL)
            q.push(curr->lc);
        if (curr->rc != NULL)
            q.push(curr->rc);
    }
}

int main(int argc, char **argv)
{
    Node *root = new Node(10);
    root->lc = new Node(20);
    root->lc->lc = new Node(40);
    root->rc = new Node(30);
    root->rc->rc = new Node(90);
    BFS(root);
}