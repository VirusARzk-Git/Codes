#include <iostream>
#include <unordered_map>
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

void fixBST(Node *root)
{
    static Node *prev = NULL, *first = NULL, *second = NULL;
    if (root == NULL)
        return;
    fixBST(root->lc);
    if (prev != NULL && root->key < prev->key)
    {
        if (first == NULL)
            first = prev;
        second = root;
    }
    prev = root;
    fixBST(root->rc);
}

void BFS(Node *root)
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
            cout << curr->key << ' ';
            if (curr->lc != NULL)
                q.push(curr->lc);
            if (curr->rc != NULL)
                q.push(curr->rc);
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(16);
    root->lc = new Node(5);
    root->lc->lc = new Node(3);
    root->rc = new Node(20);
    root->rc->lc = new Node(18);
    root->rc->lc->lc = new Node(15);
    root->rc->rc = new Node(80);
    BFS(root);
    fixBST(root);
    BFS(root);
}