#include <iostream>
#include <unordered_set>
using namespace std;

bool isPair(int *arr, int n, int sm)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.count(sm - arr[i]))
            return true;
        s.insert(arr[i]);
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    if (isPair(arr, n, target))
        cout << "Pair exists!" << endl;
    else
        cout << "No such pair!" << endl;
}