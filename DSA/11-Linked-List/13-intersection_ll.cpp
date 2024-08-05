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

void printList(Node *t)
{
    while (t)
    {
        cout << t->data << ' ';
        t = t->next;
    }
    cout << endl;
}

// void intersection(Node *t1, Node *t2)
// {
//     unordered_set<Node *> s;
//     while (t1)
//         s.insert(t1), t1 = t1->next;
//     while (t2)
//         if (s.count(t2))
//         {
//             cout << t2->data << endl;
//             return;
//         }
//         else
//             t2 = t2->next;
// }

/*

Method 2

Count Nodes in both
Traverse the bigger list abs(c1-c2) times.
Traverse both simultaneously until the common node is found

*/

int getDifference(Node *A, Node *B)
{
    int c1 = 0, c2 = 0;
    while (A)
        A = A->next, c1++;
    A = B;
    while (A)
        A = A->next, c2++;
    return c1 - c2;
}

Node *intersection(Node *A, Node *B)
{
    int d = getDifference(A, B);
    if (d < 0)
    {
        Node *head1 = A;
        A = B;
        B = head1;
        d = abs(d);
    }
    while (d)
        A = A->next, d--;
    while (A && B)
    {
        if (A == B)
            return A;
        A = A->next, B = B->next;
    }
    return NULL;
}

int main()
{
    Node *head = NULL;
    head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(23);
    head->next->next->next = new Node(42);
    head->next->next->next->next = new Node(53);
    head->next->next->next->next->next = new Node(75);
    head->next->next->next->next->next->next = new Node(79);
    head->next->next->next->next->next->next->next = new Node(90);
    printList(head);

    Node *head2 = NULL;
    head2 = new Node(18);
    head2->next = new Node(31);
    head2->next->next = head->next->next->next;
    printList(head2);

    // int d = getDifference(head, head2);
    // if (d < 0)
    // {
    //     Node *head1 = head;
    //     head = head2;
    //     head2 = head1;
    //     d = abs(d);
    // }

    Node *i = intersection(head, head2);
    printList(i);
    return 0;
}