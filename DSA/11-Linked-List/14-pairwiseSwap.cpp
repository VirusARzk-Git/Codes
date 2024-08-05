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

void pairwiseSwap(Node *t = head) // Swapping Data
{
    while (t && t->next)
        swap(t->data, t->next->data), t = t->next->next;
}

void pairwiseSwapp(Node *t = head) // Changing Pointers
{
    if (!head || !head->next)
        return;

    Node *curr = head->next->next;
    Node *prev = head;

    head = head->next;
    head->next = prev;
    while (curr && curr->next)
    {
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
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
    // head->next->next->next->next->next->next->next = new Node(90);
    printList(head);

    pairwiseSwapp();
    printList(head);

    return 0;
}