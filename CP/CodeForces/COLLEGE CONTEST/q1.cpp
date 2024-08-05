/*
Aditya Raj
*/
// #include <string>
#include <bits/stdc++.h>
using namespace std;

#define llnum unsigned long long int
#define fast_virus     \
    int virus_arzk;    \
    cin >> virus_arzk; \
    while (virus_arzk--)
#define input_array             \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out_array               \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, max = 0, index;
    cin >> n;
    vector<string> names;
    unordered_map<string, int> v;
    // map<int, string> v;
    string key;
    // vector<pair<string, int>> v;
    for (int i = 0; i < n; i++)
    {
        string name;
        int score;
        cin >> name >> score;
        if (v.find(name) == v.end())
            names.push_back(name);
        // if (score < 0)
        //     names.erase(name);
        // v.insert(make_pair(name, score));
        if (v[name] >= max)
        {
            max = v[name];
            names.push_back(name);
        }
        v[name] += score;
    }
    for (auto itr : names)
    {
        if (v[itr] > max)
        {
            key = itr;
            max = v[itr];
        }
    }
    // for (auto ptr : v)
    // {
    //     cout << ptr.first << ' ' << ptr.second << endl;
    //     if (ptr.second > max)
    //     {
    //         max = ptr.second;
    //         key = ptr.first;
    //     }
    // }
    cout << key;
    return 0;
}