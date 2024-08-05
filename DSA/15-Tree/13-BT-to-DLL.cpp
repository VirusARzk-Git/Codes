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

Node *BT_to_DLL(Node *root)
{
    static Node *prev = NULL;
    if (!root)
        return root;
    Node *head = BT_to_DLL(root->lc);
    if (!prev)
        head = root;
    else
    {
        root->lc = prev;
        prev->rc = root;
    }
    prev = root;
    BT_to_DLL(root->rc);
    return head;
}

void printList(Node *head)
{
    Node *prev = NULL;
    while (head)
    {
        cout << head->key << ' ';
        prev = head;
        head = head->rc;
    }
    cout << '\n';
    head = prev;
    while (head)
    {
        cout << head->key << ' ';
        head = head->lc;
    }
}

int main()
{
    Node *root = new Node(20);
    root->lc = new Node(10);
    root->lc->lc = new Node(5);
    root->lc->rc = new Node(15);
    root->rc = new Node(45);
    root->rc->rc = new Node(90);
    root->rc->lc = new Node(30);
    Node *head = BT_to_DLL(root);
    printList(head);
}