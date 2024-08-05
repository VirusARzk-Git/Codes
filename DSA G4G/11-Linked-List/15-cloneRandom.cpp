#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *random;
    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

Node *head = NULL;

void printList(Node *t)
{
    while (t)
    {
        cout << t->data << ' ';
        if (t->random)
            cout << t->random->data;
        cout << endl;
        t = t->next;
    }
}
Node *clone(Node *head)
{
    unordered_map<Node *, Node *> m;
    Node *temp, *nhead;

    temp = head;
    nhead = new Node(temp->data);
    m[temp] = nhead;

    while (temp->next != NULL)
    {
        nhead->next = new Node(temp->next->data);
        temp = temp->next;
        nhead = nhead->next;
        m[temp] = nhead;
    }
    temp = head;

    while (temp != NULL)
    {
        m[temp]->random = m[temp->random];
        temp = temp->next;
    }

    return m[head];
}

Node *cloneLinkedList(Node *head)
{
    if (head == NULL)
        return NULL;

    // Step 1: Create new nodes and insert them next to the original nodes
    Node *curr = head;
    while (curr != NULL)
    {
        Node *newNode = new Node(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }

    // Step 2: Set the random pointers of the new nodes
    curr = head;
    while (curr != NULL)
    {
        if (curr->random != NULL)
        {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Step 3: Separate the new nodes from the original nodes
    curr = head;
    Node *clonedHead = head->next;
    Node *clonedCurr = clonedHead;
    while (clonedCurr->next != NULL)
    {
        curr->next = curr->next->next;
        clonedCurr->next = clonedCurr->next->next;
        curr = curr->next;
        clonedCurr = clonedCurr->next;
    }
    curr->next = NULL;
    clonedCurr->next = NULL;

    return clonedHead;
}

int main()
{
    head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(21);

    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next->next->next;

    // head->next->next->next->next->next = new Node(75);
    // head->next->next->next->next->next->next = new Node(79);
    // head->next->next->next->next->next->next->next = new Node(90);
    printList(head);
    Node *head2 = clone(head);
    printList(head2);
    return 0;
}