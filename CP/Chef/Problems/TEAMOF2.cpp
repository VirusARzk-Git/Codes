
#include <bits/stdc++.h>
#define fast_tc \
    int t;      \
    cin >> t;   \
    while (t--)
#define input_arr               \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out_arr                 \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '
using namespace std;

int main()
{
    fast_tc
    {
        int n;
        cin >> n;
        int arr[n][6] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][0];
            int back = arr[i][0];
            while (back--)
            {
                int haay;
                cin >> haay;
                arr[i][haay] = 1;
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < 6; j++)
        //         cout << arr[i][j] << ' ';
        //     cout << endl;
        // }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][0] + arr[j][0] < 5)
                    continue;
                if ((arr[i][1] == 1 || arr[j][1] == 1) && (arr[i][2] == 1 || arr[j][2] == 1) && (arr[i][3] == 1 || arr[j][3] == 1) && (arr[i][4] == 1 || arr[j][4] == 1) && (arr[i][5] == 1 || arr[j][5] == 1))
                {
                    flag = false;
                    cout << "YES\n";
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (flag)
            cout << "NO\n";
    }
    return 0;
}