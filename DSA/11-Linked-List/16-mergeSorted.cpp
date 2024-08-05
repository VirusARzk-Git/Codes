#include <iostream>
#include <unordered_set>
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

void printList(Node *t)
{
    while (t)
    {
        cout << t->data << ' ';
        t = t->next;
    }
    cout << endl;
}

Node *merge(Node *t1, Node *t2)
{
    Node *h = NULL;
    Node *t = NULL;

    if (!t1)
        return t2;
    if (!t2)
        return t1;

    if (t1->data < t2->data)
        h = t = t1, t1 = t1->next;
    else
        h = t = t2, t2 = t2->next;

    while (t1 && t2)
        if (t1->data < t2->data)
            t->next = t1, t = t->next, t1 = t1->next;
        else
            t->next = t2, t = t->next, t2 = t2->next;

    if (t1)
        t->next = t1;
    else
        t->next = t2;

    return h;
}

int main()
{
    head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(23);
    head->next->next->next = new Node(42);
    head->next->next->next->next = new Node(53);
    head->next->next->next->next->next = new Node(75);
    head->next->next->next->next->next->next = new Node(79);
    head->next->next->next->next->next->next->next = new Node(90);
    printList(head);

    Node *head2 = NULL;
    head2 = new Node(18);
    head2->next = new Node(31);
    head2->next->next = new Node(56);
    head2->next->next->next = new Node(69);
    head2->next->next->next->next = new Node(83);
    printList(head2);

    Node *head3 = merge(head, head2);
    printList(head3);

    return 0;
}