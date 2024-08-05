#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *head = NULL;

void printList(Node *t = head)
{
    while (t)
    {
        cout << t->data << ' ';
        t = t->next;
    }
    cout << endl;
}

void insertSorted(int x, Node *t = head)
{
    Node *p = new Node(x);

    if (!head || x <= head->data)
    {
        p->next = head;
        head = p;
        return;
    }

    while (t->next && t->next->data < x)
        t = t->next;

    p->next = t->next;
    t->next = p;
}

Node *reverseInGroups(int k, Node *h)
{
    Node *curr = h;
    Node *prev = NULL;
    Node *next = NULL;
    int c = 0;
    while (curr && c < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
    }

    if (next)
    {
        Node *rest_head = reverseInGroups(k, next);
        h->next = rest_head;
    }
    return prev;
}

void reverse()
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void recReverse(Node *curr = head, Node *prev = NULL)
{
    if (curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        recReverse(next, curr);
    }
    else
        head = prev;
}

int main()
{
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    insertSorted(5);
    insertSorted(50);
    insertSorted(500);
    insertSorted(90);
    insertSorted(130);
    insertSorted(200);
    printList();

    // recReverse();
    head = reverseInGroups(3, head);
    printList();
    return 0;
}