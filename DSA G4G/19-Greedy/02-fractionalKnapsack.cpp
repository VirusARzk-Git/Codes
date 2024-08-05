#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct item
{
    int wt, value;
    double f;
    item(int a, int b)
    {
        wt = a;
        value = b;
        f = (double)b / (double)a;
    }
};

bool myCmp(item i1, item i2)
{
    return (i1.f > i2.f);
}

int maxValue(vector<item> arr, int givenCapacity)
{
    sort(arr.begin(), arr.end(), myCmp);
    double res = 0;
    int currCapacity = givenCapacity;
    for (item i : arr)
        if (currCapacity >= i.wt)
            currCapacity -= i.wt, res += i.value;
        else
        {
            res += (i.value * currCapacity / i.wt);
            return res;
        }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<item> arr;
    int givenCapa;
    cin >> givenCapa;
    for (int i = 0; i < n; i++)
    {
        int wt, v;
        cin >> wt >> v;
        arr.push_back(item(wt, v));
    }
    cout << maxValue(arr, givenCapa);
}