#include <iostream>
using namespace std;

class deque
{
    int sz, cap;
    int *arr;

public:
    deque(int x)
    {
        cap = x;
        sz = 0;
        arr = new int[cap];
    }

    bool isEmpty() { return sz == 0; }

    bool isFull() { return sz == cap; }

    void insertFront(int x)
    {
        if (isFull())
            return;
        for (int i = sz; i > 0; i++)
            arr[i] = arr[i - 1];
        arr[0] = x;
        sz++;
    }

    void insertRear(int x)
    {
        if (isFull())
            return;
        arr[sz++] = x;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return 0;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return sz - 1;
    }

    void deleteFront()
    {
        if (isEmpty())
            return;
        for (int i = 0; i < sz - 1; i++)
            arr[i] = arr[i + 1];
        sz--;
    }

    void deleteRear()
    {
        if (isEmpty())
            return;
        sz--;
    }
};

class Deque // efficient implementation
{
    int sz, cap;
    int *arr;
    int front;

public:
    Deque(int x)
    {
        cap = x;
        sz = 0;
        front = 0;
        arr = new int[cap];
    }

    bool isEmpty() { return sz == 0; }

    bool isFull() { return sz == cap; }

    int size() { return sz; }

    void insertFront(int x)
    {
        if (isFull())
            return;
        front = (front + cap - 1) % cap;
        arr[front] = x;
        size++;
    }

    void insertRear(int x)
    {
        if (isFull())
            return;
        int newRear = (front + sz) % cap;
        arr[newRear] = x;
        sz++;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return front;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return (front + sz - 1) % cap;
    }

    void deleteFront()
    {
        if (isEmpty())
            return;
        front = (front + 1) % cap;
        sz--;
    }

    void deleteRear()
    {
        if (isEmpty())
            return;
        sz--;
    }
};