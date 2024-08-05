#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int hash[100001] = {0};
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        if (!hash[arr[i]])
            cnt++;
        hash[arr[i]]++;
    }
    cout << cnt << ' ';
    for (int i = k; i < n; i++)
    {
        if (!hash[arr[i]])
            cnt++;
        if (hash[arr[i - k]] == 1)
            cnt--;
        hash[arr[i]]++;
        hash[arr[i - k]]--;
        cout << cnt << ' ';
    }
}