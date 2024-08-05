#include <bits/stdc++.h>
using namespace std;

#define B begin()
#define E end()
#define I iterator
using pii = pair<int, int>;
using vi = vector<int>;
#define int long long
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)

signed main()
{
    noTLE;
    testcase_chalao_bhai
    {
        int n, x, c, sum = 0;
        cin >> n >> x >> c;
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp + c >= x)
                sum += temp;
            else
                sum += x - c;
        }
        cout << sum << endl;
    }
    return 0;
}

// #include <stdio.h>

// int main()
// {
//     int i, T;
//     scanf("%d", &T);
//     for (i = 0; i < T; i++)
//     {
//         int N, X, C, sum = 0, SUM = 0, j;
//         scanf("%d %d %d", &N, &X, &C);
//         int A[N];
//         for (j = 0; j < N; j++)
//         {
//             scanf("%d", &A[j]);
//             if ((X - A[j]) > C)
//             {
//                 sum += C;
//                 A[j] = X;
//             }
//             SUM += A[j];
//         }
//         printf("%d\n", SUM - sum);
//     }
//     return 0;
// }