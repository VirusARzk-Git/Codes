#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *lc, *rc;
    Node(int c)
    {
        key = c;
        lc = rc = NULL;
    }
};

map<int, int> m;
void topView(Node *root, int i = 0)
{
    if (root == NULL)
        return;
    if (m.find(root->key) == m.end())
        m.insert({i, root->key});
    topView(root->lc, i - 1);
    topView(root->rc, i + 1);
}

void iterativeTopView(Node *root)
{
    if (root == NULL)
        return;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;
        q.pop();
        if (m.find(hd) == m.end())
            m[hd] = curr->key;
        if (curr->lc != NULL)
            q.push({curr->lc, hd - 1});
        if (curr->rc != NULL)
            q.push({curr->rc, hd + 1});
    }
}

int main()
{
    Node *root = new Node(15);
    root->lc = new Node(5);
    root->lc->lc = new Node(3);
    root->rc = new Node(20);
    root->rc->lc = new Node(18);
    root->rc->lc->lc = new Node(16);
    root->rc->rc = new Node(80);
    iterativeTopView(root);
    for (auto e : m)
        cout << e.second << ' ';
}