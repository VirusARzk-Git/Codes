#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq = {30, 40, 50};
    dq.push_front(5);
    dq.push_back(60);
    for (auto x : dq)
        cout << x << ' ';
    cout << endl
         << dq.front() << ' ' << dq.back() << endl;

    auto it = dq.begin();
    it++;
    dq.insert(it, 20);
    dq.pop_back();
    dq.pop_front();
    for (auto x : dq)
        cout << x << ' ';
    cout << endl;
}