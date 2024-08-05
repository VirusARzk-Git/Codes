#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#pragma GCC target("popcnt")
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
// void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }

template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

using vi = vector<int>;

#define all(x) x.begin(), x.end()

#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void code()
{
    int n, m, s, A, B;
    cin >> n >> m >> s >> A >> B;
    vi a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(all(a), greater<int>());
    sort(all(b), greater<int>());
    debug(a);
    debug(b);
    vi psa(n + 1, 0), psb(m + 1, 0);
    for (int i = 0; i < n; i++)
        psa[i + 1] = psa[i] + a[i];
    for (int i = 0; i < m; i++)
        psb[i + 1] = psb[i] + b[i];
    debug(psa);
    debug(psb);
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i * A > s)
            break;
        int ta = i, tb = (s - i * A) / B;
        tb = min(tb, m);
        int cc = psa[ta] + psb[tb];
        // debug(ta, tb, cc, psa[ta], psa[tb]);
        ans = max(ans, cc);
    }
    // for (int i = 0; i <= m; i++)
    // {
    //     if (i * B > s)
    //         break;
    //     int tb = i, ta = (s - i * B) / A;
    //     int cc = psa[ta] + psb[tb];
    //     // debug(ta, tb, cc, psa[ta], psa[tb]);
    //     ans = max(ans, cc);
    // }
    cout << ans << '\n';
}

signed main()
{
    noTLE;
    code();
    return 0;
}