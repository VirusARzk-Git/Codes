#include <iostream>
#include <stack>
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

void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->key << ' ';
    preOrder(root->lc);
    preOrder(root->rc);
}

void postOrder(Node *root)
{
    if (!root)
        return;
    postOrder(root->lc);
    postOrder(root->rc);
    cout << root->key << ' ';
}

void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->lc);
    cout << root->key << ' ';
    inOrder(root->rc);
}

void iterativeInOrder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->lc;
        }
        curr = s.top();
        s.pop();
        cout << curr->key << ' ';
        curr = curr->rc;
    }
    cout << '\n';
}

void iterativePreOrder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    Node *curr = root;
    while (!s.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            cout << curr->key << ' ';
            if (curr->rc != NULL)
                s.push(curr->rc);
            curr = curr->lc;
        }
        if (!s.empty())
        {
            curr = s.top();
            s.pop();
        }
    }
    cout << '\n';
}

int main()
{
    Node *root = new Node(10);
    root->lc = new Node(20);
    root->lc->lc = new Node(40);
    root->rc = new Node(30);
    root->rc->rc = new Node(90);
    preOrder(root);
    cout << '\n';
    inOrder(root);
    cout << '\n';
    postOrder(root);
    cout << '\n';
    iterativePreOrder(root);
    iterativeInOrder(root);
    return 0;
}