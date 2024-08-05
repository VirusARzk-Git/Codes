
#include <iostream>
#include <vector>
using namespace std;

int ans;
bool col[16], diag1[16], diag2[16], res[8][8];
void search(int r = 0)
{
    if (r == 8)
    {
        ans++;
        return;
    }
    for (int c = 0; c < 8; c++)
    {
        if (col[c] || diag1[r + c] || diag2[r - c + 7] || res[r][c])
            continue;
        else
            col[c] = diag1[r + c] = diag2[r - c + 7] = true;
        search(r + 1);
        col[c] = diag1[r + c] = diag2[r - c + 7] = false;
    }
}

signed main()
{
    vector<string> v(8);
    for (int i = 0; i < 8; i++)
        cin >> v[i];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (v[i][j] == '*')
                res[i][j] = true;
    search();
    cout << ans;
    return 0;
}