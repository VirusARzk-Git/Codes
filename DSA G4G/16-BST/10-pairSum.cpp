#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *lc, *rc;
    Node(int c)
    {
        key = c;
        lc = rc = NULL;
    }
};

bool pairSum(Node *root, int target, unordered_set<int> &s)
{
    if (root == NULL)
        return false;
    cout << "Started\n";
    if (pairSum(root->lc, target, s))
        return true;
    if (s.find(target - root->key) != s.end())
        return true;
    else
        s.insert(root->key);
    cout << "Ended\n";
    return pairSum(root->rc, target, s);
}

int main()
{
    Node *root = new Node(15);
    root->lc = new Node(5);
    root->lc->lc = new Node(3);
    root->rc = new Node(20);
    root->rc->lc = new Node(18);
    root->rc->lc->lc = new Node(16);
    root->rc->rc = new Node(80);

    while (1)
    {
        int n;
        cin >> n;
        unordered_set<int> s;
        cout << pairSum(root, n, s) << endl;
    }
}