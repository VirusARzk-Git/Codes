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

int maxLevel = 0;
void printLeftView(Node *root, int level = 1)
{
    if (!root)
        return;
    if (maxLevel < level)
    {
        cout << root->key << ' ';
        maxLevel = level;
    }
    printLeftView(root->lc, level + 1);
    printLeftView(root->rc, level + 1);
}

void leftView(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int c = q.size();
        for (int i = 0; i < c; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr->key << ' ';
            if (curr->lc != NULL)
                q.push(curr->lc);
            if (curr->rc != NULL)
                q.push(curr->rc);
        }
    }
}

int main(int argc, char **argv)
{
    Node *root = new Node(10);
    root->lc = new Node(20);
    root->lc->lc = new Node(40);
    root->rc = new Node(30);
    root->rc->rc = new Node(90);
    root->rc->rc->lc = new Node(180);
    printLeftView(root);
    // leftView(root);
}