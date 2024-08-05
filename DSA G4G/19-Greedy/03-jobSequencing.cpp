#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct job
{
    int deadline, profit;
    job(int a, int b)
    {
        deadline = a;
        profit = b;
    }
};

bool myCmp(job j1, job j2)
{
    return j1.profit > j2.profit;
}

// Job Sequencing Algorithm

int maxProfit(vector<job> arr)
{
    sort(arr.begin(), arr.end(), myCmp);
    int profit = 0;
    vector<bool> v(arr.size(), false);
    for (job j : arr)
        for (int i = j.deadline - 1; i >= 0; i--)
            if (!v[i])
            {
                v[i] = true, profit += j.profit;
                break;
            }
    return profit;
}

int main()
{
    int n;
    cin >> n;
    vector<job> arr;
    for (int i = 0; i < n; i++)
    {
        int deadline, profit;
        cin >> deadline >> profit;
        arr.push_back(job(deadline, profit));
    }
    cout << maxProfit(arr);
}