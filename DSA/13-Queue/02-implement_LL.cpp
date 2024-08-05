#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class queue // using LinkedList
{
    Node *rear;
    Node *front;
    int size;

public:
    queue(int x)
    {
        rear = NULL;
        front = NULL;
        size = 0;
    }

    bool isEmpty() { return (size == 0); }

    int size() { return size; }

    void enqueue(int x)
    {
        size++;
        Node *n = new Node(x);
        if (rear == NULL)
        {
            front = rear = n;
            return;
        }
        rear->next = n;
        rear = n;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        size--;
        Node *t = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete (t);
    }
};

int main()
{
}