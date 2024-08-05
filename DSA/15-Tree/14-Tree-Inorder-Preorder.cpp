// Constructing a tree from given pre and in traversals

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *lc, *rc;
    Node(int k)
    {
        key = k;
        rc = lc = NULL;
    }
};

void postOrder(Node *root)
{
    if (!root)
        return;
    postOrder(root->lc);
    postOrder(root->rc);
    cout << root->key << ' ';
}

Node *cTree(int *in, int *pre, int st, int end)
{
    if (st > end)
        return NULL;
    static int preIndex = 0;
    Node *root = new Node(pre[preIndex++]);
    int inIndex;
    for (int i = st; i <= end; i++)
        if (in[i] == root->key)
        {
            inIndex = i;
            break;
        }
    root->lc = cTree(in, pre, st, inIndex - 1);
    root->rc = cTree(in, pre, inIndex + 1, end);
    return root;
}

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
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int pre[n], in[n];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    Node *root = cTree(in, pre, 0, n - 1);
    BFS(root);
    postOrder(root);
}