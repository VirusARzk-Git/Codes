#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
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

void insertBegin(int d)
{
    Node *p = new Node(d);

    if (!head)
    {
        p->next = p;
        head = p;
        return;
    }
    p->next = head->next;
    head->next = p;

    swap(p->data, head->data);
}

void insertLast(int d)
{
    Node *p = new Node(d);

    if (!head)
    {
        p->next = p;
        head = p;
        return;
    }
    p->next = head->next;
    head->next = p;

    swap(p->data, head->data);
    head = head->next;
}

void deleteHead()
{
    if (!head)
        return;
    if (!head->next)
    {
        delete (head);
        head = NULL;
        return;
    }

    head = head->next;
}

void deleteAt(int k)
{
    if (k == 1)
        return deleteHead();
    Node *curr = head;
    k--;
    while (curr && --k)
        curr = curr->next;
    if (!k)
        curr->next = curr->next->next;
}

int main()
{
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    printList();

    insertBegin(5);
    insertLast(50);
    printList();

    deleteAt(2);
    deleteAt(3);
    printList();
}