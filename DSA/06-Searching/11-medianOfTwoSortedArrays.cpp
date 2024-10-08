#include <iostream>
using namespace std;

// n < m
double getMedian(int *a1, int n, int *a2, int m)
{
    int begin1 = 0, end1 = n;
    while (begin1 <= end1)
    {
        int i1 = (begin1 + end1) / 2;
        int i2 = (n + m + 1) / 2 - i1;

        int min1 = (i1 == n) ? INT_MAX : a1[i1];
        int max1 = (i1 == 0) ? INT_MIN : a1[i1 - 1];

        int min2 = (i2 == m) ? INT_MAX : a2[i2];
        int max2 = (i2 == 0) ? INT_MIN : a2[i2 - 1];

        if (max1 <= min2 && max2 <= min1)
        {
            if ((n + m) % 2 == 0)
                return (double)(max(max1, max2) + min(min1, min2)) / 2;
            else
                return (double)max(max1, max2);
        }
        else if (max1 > min2)
            end1 = i1 - 1;
        else
            begin1 = i1 + 1;
    }

    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a1[n], a2[m];
    for (int i = 0; i < n; i++)
        cin >> a1[i];
    for (int i = 0; i < m; i++)
        cin >> a2[i];
    cout << getMedian(a1, n, a2, m);
    return 0;
}