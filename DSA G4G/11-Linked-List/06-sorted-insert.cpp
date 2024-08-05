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

int main()
{
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int a;
    printList();

    cin >> a;
    insertSorted(a);
    printList();

    cin >> a;
    insertSorted(a);
    printList();

    cin >> a;
    insertSorted(a);
    printList();

    cin >> a;
    insertSorted(a);
    printList();

    cin >> a;
    insertSorted(a);
    printList();

    cin >> a;
    insertSorted(a);
    printList();

    return 0;
}