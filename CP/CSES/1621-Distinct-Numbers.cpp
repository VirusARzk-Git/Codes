#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define array_input_lelo_bhai   \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

void code_iske_andar_hai()
{
    int n;
    cin >> n;
    array_input_lelo_bhai;
    set<int> s(arr, arr + n);
    cout << s.size();
}

signed main()
{
    code_iske_andar_hai();
    return 0;
}