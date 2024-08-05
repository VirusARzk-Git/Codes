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

void segregate(Node *t = head)
{
    Node *odd = NULL;
    Node *oddH = NULL;
    Node *even = NULL;
    Node *evenH = NULL;

    while (t)
    {
        if (t->data % 2)
        {
            if (!odd)
                odd = t, oddH = t;
            else
                odd->next = t, odd = odd->next;
        }
        else
        {
            if (!even)
                even = t, evenH = t;
            else
                even->next = t, even = even->next;
        }
        t = t->next;
    }

    odd->next = NULL;
    even->next = NULL;

    if (!odd)
        head = evenH;
    else if (!even)
        head = oddH;
    else
        even->next = oddH, odd->next = NULL, head = evenH;
}

int main()
{
    head = new Node(10);
    head->next = new Node(115);
    head->next->next = new Node(23);
    head->next->next->next = new Node(142);
    head->next->next->next->next = new Node(53);
    head->next->next->next->next->next = new Node(75);
    head->next->next->next->next->next->next = new Node(74);
    head->next->next->next->next->next->next->next = new Node(90);
    printList();

    segregate();
    printList();
    return 0;
}