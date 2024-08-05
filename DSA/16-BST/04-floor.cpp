#include <iostream>
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

int floor(Node *root, int x)
{
    int ans = -1;
    while (root)
    {
        if (root->key == x)
            return x;
        if (root->key < x)
            ans = max(ans, root->key), root = root->rc;
        else if (root->key > x)
            root = root->lc;
    }
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
    int n;
    cin >> n;
    cout << floor(root, n);
}

//         15
//     5       20
// 3       18      80
//     16