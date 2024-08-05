#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MSIS(int *arr, int n)
{
    vector<int> msis(n);
    for (int i = 0; i < n; i++)
    {
        msis[i] = arr[i];
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                msis[i] = max(msis[i], msis[j] + arr[i]);
    }
    return *max_element(msis.begin(), msis.end());
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << MSIS(arr, n) << endl;
}