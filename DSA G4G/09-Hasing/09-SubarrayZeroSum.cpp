#include <iostream>
#include <unordered_set>
using namespace std;

bool is0Subarray(int *arr, int n)
{
    unordered_set<int> s;
    int preSum = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (s.count(preSum))
            return true;
        if (preSum == 0)
            return true;
        s.insert(preSum);
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
    if (is0Subarray(arr, n))
        cout << "Subarray exists!" << endl;
    else
        cout << "No such subarray!" << endl;
}