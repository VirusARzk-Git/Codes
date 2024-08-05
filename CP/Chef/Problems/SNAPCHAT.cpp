#include <stdio.h>
/*
Aditya Raj
*/
#include <bits/stdc++.h>
// #include <string>
// #include <conio.h>
// #include <stdio.h>
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
#define array_input_lelo_bhai   \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define array_print_kardo_bhai  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

signed main()
{
    noTLE;
    int T, i;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        int n, j, count = 0, max = 0;
        cin >> n;
        int arr[n];
        for (j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        int brr[n];
        for (j = 0; j < n; j++)
        {
            cin >> brr[j];
        }
        for (int j = 0; j < n; j++)
        {
            if ((brr[j] != 0) && (arr[j] != 0))
            {
                count++;
            }
            else
            {
                if (max < count)
                    max = count;
                count = 0;
            }
        }
        if (max < count)
            max = count;
        cout << max << endl;
    }
    return 0;
}

// #include <stdio.h>

// int main(void)
// {
//     int T, i;
//     scanf("%d", &T);
//     for (i = 0; i < T; i++)
//     {
//         int S, k = 0, N, j, count = 0;
//         scanf("%d", &N);
//         int A[N], B[N], C[N];

//         for (j = 0; j < N; j++)
//         {
//             scanf("%d", &A[j]);
//         }
//         for (j = 0; j < N; j++)
//         {
//             scanf("%d", &B[j]);
//         }
//         for (j = 0; j < N; j++)
//         {
//             if ((A[j] != 0) && (B[j] != 0))
//             {
//                 count++;
//             }
//             else
//             {
//                 C[k++] = count;
//                 count = 0;
//                 S = k;
//             }
//         }

//         C[k++] = count;
//         S = k;
//         for (k = 1; k < S; k++)
//         {
//             if (C[0] < C[i])
//             {
//                 C[0] = C[i];
//             }
//         }
//         printf("%d\n", C[0]);
//     }
//     return 0;
// }