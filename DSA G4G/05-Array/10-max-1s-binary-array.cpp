#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt = 0, t_cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            cnt = max(cnt, ++t_cnt);
        else
            t_cnt = 0;
    }
    cout << cnt << endl;
}