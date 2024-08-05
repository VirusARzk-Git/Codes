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

Node *getSucc(Node *curr)
{
    curr = curr->rc;
    while (curr != NULL && curr->lc != NULL)
        curr = curr->lc;
    return curr;
}

Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
        return root;
    if (root->key > x)
        root->lc = deleteNode(root->lc, x);
    else if (root->key < x)
        root->rc = deleteNode(root->rc, x);
    else
    {
        if (root->lc == NULL)
        {
            Node *t = root->rc;
            delete (root);
            return t;
        }
        else if (root->rc == NULL)
        {
            Node *t = root->lc;
            delete (root);
            return t;
        }
        else
        {
            Node *succ = getSucc(root);
            root->key = succ->key;
            root->rc = deleteNode(root->rc, succ->key);
        }
    }
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
    deleteNode(root, 20);
    deleteNode(root, 16);
    BFS(root);
}

//         15
//     5       20
// 3       18      80
//     16