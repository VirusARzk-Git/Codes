#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;

    Node(int d)
    {
        prev = NULL;
        next = NULL;
        data = d;
    }
};

Node *head = NULL;

void printList(Node *t = head)
{
    if (!head)
        return;
    do
    {
        cout << t->data << ' ';
        t = t->next;
    } while (t != head);
    cout << endl;
}

void RevprintList(Node *t = head)
{
    if (!head)
        return;
    do
    {
        t = t->prev;
        cout << t->data << ' ';
    } while (t != head);
    cout << endl;
}

void InsertHead(int d)
{
    Node *p = new Node(d);

    if (!head)
    {
        p->next = p;
        p->prev = p;
        head = p;

        return;
    }
    head->prev->next = p;
    p->prev = head->prev;
    head->prev = p;
    p->next = head;
    head = head->prev;
}

void InsertLast(int d)
{
    Node *p = new Node(d);

    if (!head)
    {
        p->next = p;
        p->prev = p;
        head = p;

        return;
    }

    p->prev = head->prev;
    p->next = head;
    head->prev->next = p;
    head->prev = p;
}

int main()
{
    head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->prev = new Node(5);
    head->prev->next = head;
    head->prev->prev = head->next;
    head->next->next = head->prev;
    head = head->prev;

    printList();
    InsertHead(3);
    InsertLast(29);
    RevprintList();
}