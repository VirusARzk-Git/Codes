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

struct stack
{
    Node *head;
    int sz;

    stack()
    {
        head = NULL;
        sz = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }

    int pop()
    {
        if (!head)
            return INT_MAX;
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete (temp);
        sz--;
    }

    int size()
    {
        return sz;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    int peek()
    {
        if (head == NULL)
            return INT_MAX;
        return head->data;
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(10);
    s.push(100);
    // cout << s.pop() << endl;
    cout << s.peek() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    cout << s.size() << endl;
}