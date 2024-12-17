class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        set<int> s(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        map<int, int> maxi;
        int ans = -1;
        for (int i : nums)
        {
            int sq = sqrt(i);
            if (sq * sq != i)
            {
                maxi[i] = 1;
                continue;
            }
            if (s.count(sq) == 0)
            {
                maxi[i] = 1;
                continue;
            }
            else
                maxi[i] = 1 + maxi[sq];
            ans = max(ans, maxi[i]);
        }
        return ans;
    }
};