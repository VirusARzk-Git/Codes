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

void printList(Node *curr = head)
{
    while (curr)
    {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
}

void insertSorted(int x, Node *curr = head)
{
    Node *p = new Node(x);

    if (!head || x <= head->data)
    {
        p->next = head;
        head = p;
        return;
    }

    while (curr->next && curr->next->data < x)
        curr = curr->next;

    p->next = curr->next;
    curr->next = p;
}

void removeDuplicatesInSorted(Node *curr = head)
{
    Node *next = curr->next;
    while (next)
    {
        if (curr->data == next->data)
            curr->next = next->next, delete (next);
        else
            curr = next;
        next = curr->next;
    }
}

int main()
{
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    insertSorted(5);
    insertSorted(50);
    insertSorted(50);
    insertSorted(90);
    insertSorted(10);
    insertSorted(20);
    printList();

    removeDuplicatesInSorted();
    printList();
    return 0;
}