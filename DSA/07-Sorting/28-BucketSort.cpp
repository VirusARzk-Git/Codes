#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BucketSort(int *arr, int n, int k)
{
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
        max_val = max(max_val, arr[i]);
    max_val++;
    vector<int> bkt[k];
    for (int i = 0; i < n; i++)
    {
        int bi = (k * arr[i]) / max_val;
        bkt[bi].push_back(arr[i]);
    }
    for (int i = 0; i < k; i++)
        sort(bkt[i].begin(), bkt[i].end());
    int idx = 0;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < bkt[i].size(); j++)
            arr[idx++] = bkt[i][j];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    BucketSort(arr, n, k);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}