#include <iostream>
#include <unordered_set>
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
    } while (t != head && t != NULL);
    cout << endl;
}

bool detectLoopUsingHashing(struct Node *h)
{
    unordered_set<Node *> s;
    while (h != NULL)
    {
        if (s.count(h))
            return true;
        s.insert(h);
        h = h->next;
    }
    return false;
}

bool detectLoop(Node *t = head) // Floyd
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next, fast = fast->next->next;
        if (slow == fast)
        {
            cout << slow->data << endl;
            return true;
        }
    }
    return false;
}

void removeLoop(Node *t = head)
{
    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next, fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow != fast)
        return;

    slow = head;
    if (slow == fast)
        while (fast->next != slow)
            fast = fast->next;
    else
        while (slow->next != fast->next)
            slow = slow->next, fast = fast->next;
    fast->next = NULL;
}

int main()
{
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    // printList();

    cout << detectLoop(head) << endl;
    removeLoop(head);
    cout << detectLoop(head) << endl;
    printList();
}