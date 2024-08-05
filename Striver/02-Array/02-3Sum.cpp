#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
// #define vi vector<int>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            break;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int x = nums[i] + nums[j] + nums[k];
            if (x < 0)
                j++;
            else if (x > 0)
                k--;
            else
            {
                s.insert({nums[i], nums[j], nums[k]});
                j++, k--;
                while (nums[j] == nums[j - 1])
                    j++;
                while (nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    vector<vector<int>> ans;
    for (auto e : s)
        ans.push_back(e);
    return ans;
}

int main()
{
}