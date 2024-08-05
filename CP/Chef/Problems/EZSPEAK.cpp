#include <bits/stdc++.h>
#define fast_tc \
    int t;      \
    cin >> t;   \
    while (t--)
// #define input_arr int arr[n]; for(int i=0;i<n;i++) cin>>arr[i]
// #define out_arr for(int i=0;i<n;i++) cout<<arr[i]<<' '
using namespace std;
#define hey_there            \
    int n;                   \
    string s, str = "YES\n"; \
    cin >> n;                \
    cin >> s;
#define Just_A_Small_Piece_Of_Code \
    if (check(s[i]))               \
        continue;                  \
    if (check(s[i + 1]))           \
    {                              \
        i++;                       \
        continue;                  \
    }                              \
    if (check(s[i + 2]))           \
    {                              \
        i += 2;                    \
        continue;                  \
    }                              \
    if (check(s[i + 3]))           \
    {                              \
        i += 3;                    \
        continue;                  \
    }                              \
    str = "NO\n";                  \
    break
bool check(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    else
        return false;
}

int main()
{
    fast_tc
    {
        hey_there for (int i = 0; i < n - 3; i++)
        {
            Just_A_Small_Piece_Of_Code;
        }
        cout << str;
    }
    return 0;
}