#include <iostream>

// FIFO - First In First Out

class queue
{
    int size, cap;
    int *arr;

    queue(int x)
    {
        cap = x;
        size = 0;
        arr = new int[cap];
    }

    bool isFull() { return (size == cap); }
    bool isEmpty() { return (size == 0); }

    void enqueue(int x)
    {
        if (isFull())
            return;
        arr[size++] = x;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return 0;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return size - 1;
    }
};

class queuee // Efficient using Circular Array
{
    int size, cap, front;
    int *arr;

    queuee(int x)
    {
        cap = x;
        size = 0;
        front = 0;
        arr = new int[cap];
    }

    bool isFull() { return (size == cap); }
    bool isEmpty() { return (size == 0); }

    void enqueue(int x)
    {
        if (isFull())
            return;
        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        front = (front + 1) % cap;
        size--;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return front;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return (front + size - 1) % cap;
    }
};

int main()
{
}