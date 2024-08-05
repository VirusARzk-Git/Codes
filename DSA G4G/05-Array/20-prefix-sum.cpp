#include <iostream>
using namespace std;
#define int long long int
signed main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int prefixSum[n + 1] = {0};
    for (int i = 0; i < n; i++)
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << prefixSum[b] - prefixSum[a-1] << endl;
    }
}