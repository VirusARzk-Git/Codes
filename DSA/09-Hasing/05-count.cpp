#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int countDistinct(int *arr, int n)
{
    unordered_set<int> s(arr, arr + n);
    return s.size();
}

void countFreq(int *arr, int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    for (auto e : m)
        cout << e.first << " " << e.second << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countDistinct(arr, n) << endl;
    countFreq(arr, n);
}