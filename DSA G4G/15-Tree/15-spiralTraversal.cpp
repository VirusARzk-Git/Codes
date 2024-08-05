#include <iostream>
#include <deque>
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

void spiralTraversal(Node *root)
{
    if (root == NULL)
        return;
    deque<Node *> dq;
    dq.push_back(root);
    bool reverse = false;
    while (!dq.empty())
    {
        int c = dq.size();
        if (flag)
        {
            for (int i = 0; i < c; i++)
            {
                Node *curr = dq.front();
                dq.pop_front();
                cout << curr->key << ' ';
                if (curr->lc != NULL)
                    dq.push_back(curr->lc);
                if (curr->rc != NULL)
                    dq.push_back(curr->rc);
            }
            flag = !flag;
        }
        else
        {
            for (int i = 0; i < c; i++)
            {
                Node *curr = dq.back();
                dq.pop_back();
                cout << curr->key << ' ';
                if (curr->rc != NULL)
                    dq.push_front(curr->rc);
                if (curr->lc != NULL)
                    dq.push_front(curr->lc);
            }
            flag = !flag;
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->lc = new Node(20);
    root->lc->lc = new Node(40);
    root->rc = new Node(30);
    root->rc->rc = new Node(90);
    spiralTraversal(root);
}