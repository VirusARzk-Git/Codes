#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *t)
{
    while (t)
    {
        cout << t->data;
        t = t->next;
    }
    cout << endl;
}

Node *reverse(Node *t)
{
    Node *prev = NULL;
    Node *curr = t;
    while (curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    Node *fast = head, *slow = head;

    while (fast->next && fast->next->next)
        slow = slow->next, fast = fast->next->next;

    slow->next = reverse(slow->next);
    Node *rev = slow->next;

    Node *curr = head;
    while (rev)
    {
        if (rev->data != curr->data)
            return false;
        rev = rev->next;
        curr = curr->next;
    }
    return true;
}

int main()
{
    Node *head = NULL;
    head = new Node('R');
    head->next = new Node('A');
    head->next->next = new Node('D');
    head->next->next->next = new Node('A');
    head->next->next->next->next = new Node('R');

    printList(head);

    cout << isPalindrome(head) << endl;
    printList(head);

    return 0;
}