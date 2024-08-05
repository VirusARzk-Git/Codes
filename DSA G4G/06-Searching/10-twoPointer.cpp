#include <iostream>
using namespace std;

// Given a Sorted Array and a sum, find if there is a pair with the given sum
bool pairSum(int *arr, int left, int right, int val)
{
    while (left < right)
    {
        int x = arr[left] + arr[right];
        if (x == val)
        {
            cout << left << " " << right << endl;
            return true;
        }
        else if (x > val)
            right--;
        else
            left++;
    }
    cout << "No such pair!" << endl;
    return false;
}

// Given a Sorted Array and a sum, find if there is a triplet with the given sum
bool tripletSum(int *arr, int n, int val)
{
    for (int i = 0; i < n; i++)
        if (pairSum(arr, i + 1, n - 1, val - arr[i]))
            return true;
    return false;
}

//  Find a pythagorean triplet if it exists
bool isPair(int *arr, int left, int right, int val)
{
    int last = right + 1;
    while (left < right)
    {
        int x = arr[left] * arr[left] + arr[right] * arr[right];
        if (x == val)
        {
            cout << arr[left] << ' ' << arr[right] << ' ' << arr[last] << '\n';
            return true; // Remove this to get all pythagorean triplets
            // return false;
        }
        else if (x > val)
            right--;
        else
            left++;
    }
    // cout << "No such pair!" << endl;
    return false;
}

bool pythagorean(int *arr, int n)
{
    if (n < 3)
        return false;
    for (int i = n - 1; i > 1; i--)
        if (isPair(arr, 0, i - 1, arr[i] * arr[i]))
            return true;
    return false;
}

int main()
{
    int n, val;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (pythagorean(arr, n))
        cout << "Yes";
    else
        cout << "No";
}