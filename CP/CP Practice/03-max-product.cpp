/*

Given an array A, of N integers A.

Return the highest product possible by multiplying 3 numbers from the array.

*/


#include <bits/stdc++.h>
using namespace std;

#define llnum long long int
#define fast_virus     \
    int virus_arzk;    \
    cin >> virus_arzk; \
    while (virus_arzk--)
#define input_array             \
    llnum arr[n];               \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

int main()
{
    int n;
    cin >> n;
    input_array;
    sort(arr, arr + n);
    cout << ((arr[0] * arr[1] * arr[n - 1]) > (arr[n - 2] * arr[n - 3] * arr[n - 1]) ? (arr[0] * arr[1] * arr[n - 1]) : (arr[n - 2] * arr[n - 3] * arr[n - 1]));
    return 0;
}