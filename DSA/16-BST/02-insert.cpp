#include <iostream>
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

Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    else if (root->key < x)
        root->rc = insert(root->rc, x);
    else if (root->key > x)
        root->lc = insert(root->lc, x);
    return root;
}

Node *iterativeInsert(Node *root, int x)
{
    Node *temp = new Node(x);
    Node *parent = NULL, *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->key > x)
            curr = curr->lc;
        else if (curr->key < x)
            curr = curr->rc;
        else
            return root;
    }
    if (parent == NULL)
        return temp;
    if (parent->key > x)
        parent->lc = temp;
    else
        parent->rc = temp;
    return root;
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
    Node *root = new Node(15);
    root->lc = new Node(5);
    root->lc->lc = new Node(3);
    root->rc = new Node(20);
    root->rc->lc = new Node(18);
    root->rc->lc->lc = new Node(16);
    root->rc->rc = new Node(80);
    iterativeInsert(root, 10);
    insert(root, 8);
    BFS(root);
}