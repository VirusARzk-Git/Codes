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

Node *insertBegin(Node *head, int data)
{
    Node *p = new Node(data);
    p->next = head;
    return p;
}

Node *insertEnd(Node *head, int data)
{
    Node *p = head;
    Node *t = new Node(data);
    if (head == NULL)
        return t;

    while (p->next != NULL)
        p = p->next;
    p->next = t;
    return head;
}

Node *insert(Node *head, int data, int pos)
{
    Node *p = new Node(data);

    if (pos == 1)
    {
        p->next = head;
        return p;
    }

    Node *t = head;
    --pos;
    while (t and --pos)
        t = t->next;

    if (pos == 0)
    {
        p->next = t->next;
        t->next = p;
    }

    return head;
}

int search(Node *head, int data)
{
    int pos = 1;
    while (head)
    {
        if (head->data == data)
            return pos;
        pos++;
        head = head->next;
    }
    return -1;
}

int Rsearch(Node *head, int data, int pos = 1)
{
    if (!head)
        return -1;

    if (head->data == data)
        return pos;
    else
        return Rsearch(head = head->next, data, pos + 1);
}

Node *deleteBegin(Node *head)
{
    if (!head)
        return NULL;

    Node *t = head;
    head = head->next;
    delete (t);
    return head;
}

Node *deleteLast(Node *head)
{
    if (!head || !head->next)
        return NULL;

    Node *t = head;
    while (t->next->next != NULL)
        t = t->next;
    delete (t->next);
    t->next = NULL;
    return head;
}

void printList(Node *t)
{
    while (t)
    {
        cout << t->data << ' ';
        t = t->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printList(head);

    head = insertBegin(head, 8);
    head = insertBegin(head, 5);
    head = insertBegin(head, 3);
    head = insertBegin(head, 1);
    head = insertEnd(head, 69);
    head = insertEnd(head, 84);
    head = insertEnd(head, 100);
    printList(head);

    head = deleteBegin(head);
    head = deleteBegin(head);
    head = deleteLast(head);
    head = deleteLast(head);
    printList(head);

    head = insert(head, 2, 9);
    head = insert(head, 4, 7);
    head = insert(head, 6, 3);
    head = insert(head, 7, 7);
    head = insert(head, 9, 4);
    head = insert(head, 93, 5);
    head = insert(head, 87, 10);
    printList(head);
    head = insert(head, 120, 7);
    printList(head);

    cout << search(head, 87) << endl;
    cout << Rsearch(head, 120) << endl;

    return 0;
}