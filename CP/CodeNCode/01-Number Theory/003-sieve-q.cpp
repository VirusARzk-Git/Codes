#include <iostream>
#include <vector>
using namespace std;

int n = 90000001;

vector<int> primes;
bool is_Prime[90000001] = {true, true};
void sieve()
{
    for (int i = 2; i * i < n; i++)
    {
        if (is_Prime[i] == false)
        {
            // primes.push_back(i);
            for (int j = i * i; j < n; j += i)
            {
                is_Prime[j] = true;
            }
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (is_Prime[i] == false)
            primes.push_back(i);
    }
}

int main()
{
    sieve();
    int q, t;
    cin >> q;
    while (q--)
        cin >> t, cout << primes[t - 1] << endl;
    return 0;
}
