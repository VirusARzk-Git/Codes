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

void nthFromEnd(int n)
{
    Node *front = head;
    Node *back = head;
    int fr = 0;
    while (front)
    {
        if (fr >= n)
            back = back->next;
        front = front->next;
        fr++;
    }
    cout << back->data << endl;
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

    nthFromEnd(6);
    return 0;
}