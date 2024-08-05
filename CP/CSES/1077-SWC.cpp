#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

signed main()
{
    ordered_set os;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++)
        os.insert(arr[i]);
    vector<int> ans;
    int indexOfMedian = (k - 1) / 2;
    int sum = 0;
    int median = *os.find_by_order(indexOfMedian);
    for (int i = 0; i < k; i++)
        sum += abs(median - arr[i]);
    ans.push_back(sum);
    for (int i = k; i < n; i++)
    {
        int old = median;
        os.erase(os.find_by_order(os.order_of_key(arr[i - k])));
        os.insert(arr[i]);
        sum -= abs(old - arr[i - k]);
        sum += abs(old - arr[i]);
        median = *os.find_by_order(indexOfMedian);
        int diff = median - old;
        if (diff == 0)
        {
            ans.push_back(sum);
            continue;
        }
        if (median < old) // median is less than old
        {
            int c = os.order_of_key(old);
            sum += (k - 2 * c) * abs(diff);
        }
        else if (median > old) // median is greater than old
        {
            int c = os.order_of_key(median);
            sum += (2 * c - k) * abs(diff);
        }
        ans.push_back(sum);
    }
    for (auto i : ans)
        cout << i << " ";
    return 0;
}