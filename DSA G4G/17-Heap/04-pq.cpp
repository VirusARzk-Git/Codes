#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Person
{
    int age;
    float ht;
    Person(int a, int h)
    {
        age = a;
        ht = h;
    }
};

struct myCmp
{
    bool operator()(Person const &p1, Person const &p2)
    {
        return p1.ht < p2.ht;
    }
};

int main()
{
    priority_queue<Person, vector<Person>, myCmp> pQ;
}