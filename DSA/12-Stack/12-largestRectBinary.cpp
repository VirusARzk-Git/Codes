#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRecAreaHistogram(vector<int> &arr) // efficient implementation
{
    int n = arr.size();
    stack<int> s;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            int tp = s.top();
            s.pop();
            int curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
            res = max(res, curr);
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int tp = s.top();
        s.pop();
        int curr = arr[tp] * (s.empty() ? n : (n - s.top() - 1));
        res = max(res, curr);
    }
    return res;
}

int largestRect(vector<vector<int>> v)
{
    int R = v.size();
    int C = v[0].size();
    int ans = largestRecAreaHistogram(v[0]);

    for (int i = 1; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            if (v[i][j])
                v[i][j] += v[i - 1][j];
        ans = max(ans, largestRecAreaHistogram(v[i]));
    }

    return ans;
}

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> mat;

    for (int i = 0; i < R; i++)
    {
        vector<int> v(C);
        for (int i = 0; i < C; i++)
            cin >> v[i];
        mat.push_back(v);
    }

    cout << largestRect(mat) << endl;
}