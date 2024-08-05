#include <iostream>
#include <map>
#include <vector>
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

void vSumR(Node *root, map<int, int> &m, int i = 0)
{
    if (root == NULL)
        return;
    vSumR(root->lc, m, i - 1);
    m[i] += root->key;
    vSumR(root->rc, m, i + 1);
}

vector<int> verticalSum(Node *root)
{
    vector<int> ans;
    map<int, int> m;
    vSumR(root, m);
    for (auto e : m)
        ans.push_back(e.second);
    return ans;
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
    vector<int> v = verticalSum(root);
}