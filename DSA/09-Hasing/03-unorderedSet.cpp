#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(11);
    s.insert(34);
    s.insert(52);
    s.insert(1);

    // for (int x : s)
    //     cout << x << ' ';

    // for (auto it = s.begin(); it != s.end(); it++)
    //     cout << *it << ' ';

    int x = 34;
    // if (s.find(x) == s.end())
    //     cout << "Not Found\n";
    // else
    //     cout << "Found " << *(s.find(x)) << "\n";

    if (s.count(x))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    cout << s.size() << '\n';

    // s.clear();

    // s.erase(34);
    // s.erase(s.count(x));

    s.erase(s.begin(), s.end());

    cout << s.size() << '\n';

    return 0;
}