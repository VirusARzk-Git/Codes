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
Node *tail = NULL;

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}

void RevprintList(Node *tail)
{
    while (tail)
    {
        cout << tail->data << ' ';
        tail = tail->prev;
    }
    cout << '\n';
}

Node *insertBegin(Node *head, int d)
{
    Node *p = new Node(d);
    p->next = head;
    if (!head)
        tail = p;
    else
        head->prev = p;
    return p;
}

Node *insertEnd(Node *tail, int d)
{
    Node *p = new Node(d);
    if (!tail)
        head = p;
    else
    {
        tail->next = p;
        p->prev = tail;
    }
    return p;
}

void reverse()
{
    Node *a = head;
    Node *ptr = NULL;
    while (a)
    {
        ptr = a->next;
        a->next = a->prev;
        a->prev = ptr;
        a = a->prev;
    }
    ptr = head;
    head = tail;
    tail = ptr;
}

void deleteFirst()
{
    if (!head)
        return;

    if (head->next)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    head = head->next;
    head.prev = NULL;
}

void deleteLast()
{
    if (!tail)
        return;

    if (tail->prev)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    tail = tail->prev;
    tail->next = NULL;
}

int main()
{
    head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->prev = new Node(5);
    head->prev->next = head;
    tail = head->next;
    head = head->prev;
    printList(head);

    head = insertBegin(head, 3);
    tail = insertEnd(tail, 30);

    printList(head);
    RevprintList(tail);

    reverse();
    printList(head);

    deleteFirst();
    deleteLast();
    printList(head);
}