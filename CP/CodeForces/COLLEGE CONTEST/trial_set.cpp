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
    unordered_set<string> stt;
    stt.insert("Aditya");
    stt.insert("Ankit");
    stt.insert("Aditya");
    stt.insert("Aman");
    stt.insert("Ankit");
    for (auto itr : stt)
        cout << itr << ' ';
    return 0;
}