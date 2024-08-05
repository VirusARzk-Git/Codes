#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> m;
    m["gfg"] = 30;
    m["ide"] = 20;
    m.insert({"dsa", 10});
    for (auto x : m)
        cout << x.first << ' ' << x.second << endl;

    // if (m.find("ide") != m.end())
    if (m.count("ide"))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    m.erase("ide");

    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->first << ' ' << it->second << endl;

    m.erase(m.begin(), m.end());

    return 0;
}