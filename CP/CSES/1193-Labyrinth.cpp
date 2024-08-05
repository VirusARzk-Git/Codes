#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
int n, m;
vector<string> maze;

bool isValid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m || maze[i][j] != '.' && maze[i][j] != 'B')
        return false;
    return true;
}

string dirr = "RDLU";
int dir[] = {0, 1, 0, -1, 0};
int endi, endj, starti, startj;

void bfs(int i, int j)
{
    queue<pii> q;
    q.push({i, j});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        if (p.first == endi && p.second == endj)
        {
            cout << "YES\n";
            string ans = "";
            int ii = p.first, jj = p.second;
            while (maze[ii][jj] != 'A')
            {
                ans += maze[ii][jj];
                if (maze[ii][jj] == 'R')
                    jj--;
                else if (maze[ii][jj] == 'L')
                    jj++;
                else if (maze[ii][jj] == 'U')
                    ii++;
                else
                    ii--;
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            cout << ans;
            exit(0);
        }
        for (int k = 0; k < 4; k++)
        {
            int x = p.first + dir[k], y = p.second + dir[k + 1];
            if (isValid(x, y))
            {
                q.push({x, y});
                maze[x][y] = dirr[k];
            }
        }
    }
}

void code()
{
    cin >> n >> m;
    maze.resize(n);
    for (int i = 0; i < n; i++)
        cin >> maze[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == 'A')
                starti = i, startj = j;
            if (maze[i][j] == 'B')
                endi = i, endj = j;
        }
    }
    bfs(starti, startj);
    cout << "NO";
}

signed main()
{
    code();
    return 0;
}