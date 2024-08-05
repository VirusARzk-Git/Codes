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

int maxWidth(Node *root)
{
    if (!root)
        return 0;
    queue<Node *> q;
    q.push(root);
    int ans = 0;
    while (!q.empty())
    {
        int c = q.size();
        ans = max(ans, c);
        for (int i = 0; i < c; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->lc)
                q.push(curr->lc);
            if (curr->rc)
                q.push(curr->rc);
        }
    }
    return ans;
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

    cout << maxWidth(root);
}