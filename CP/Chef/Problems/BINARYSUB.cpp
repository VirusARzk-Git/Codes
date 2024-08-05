/*
Aditya Raj
*/
// #include <string>
#include <bits/stdc++.h>
using namespace std;
#define pb lengths_of_alternating_ab.push_back(cnt)
#define chotka_wala_number int
#define badka_wala_number long long int
#define badka_wala_positive_number unsigned badka_wala_number
#define testcase_chalao_bhai       \
    chotka_wala_number virus_arzk; \
    cin >> virus_arzk;             \
    while (virus_arzk--)
#define array_input_lelo_bhai                  \
    chotka_wala_number arr[n];                 \
    for (chotka_wala_number i = 0; i < n; i++) \
    cin >> arr[i]

badka_wala_number func(badka_wala_number niche_wala, chotka_wala_number upar_wala, chotka_wala_number p)
{
    badka_wala_number res = 1;
    niche_wala = niche_wala % p;
    while (upar_wala > 0)
    {
        if (upar_wala % 2 == 1)
        {
            res = (res * niche_wala) % p;
        }
        upar_wala = upar_wala >> 1;
        niche_wala = (niche_wala * niche_wala) % p;
    }
    return res;
}

chotka_wala_number main()
{
    chotka_wala_number p = 998244353;
    for (int i = 0; i < 5; i++)
        ;
    vector<badka_wala_number> factorial_calc;
    factorial_calc.push_back(1);
    badka_wala_number initial = 1;
    for (chotka_wala_number i = 1; i <= 100000; i++)
    {
        initial *= i;
        initial %= p;
        factorial_calc.push_back(initial);
    }
    for (int i = 0; i < 5; i++)
        ;
    for (int i = 0; i < 5; i++)
        ;
    testcase_chalao_bhai
    {
        string mera_string_variable;
        cin >> mera_string_variable;
        chotka_wala_number l = mera_string_variable.length();

        chotka_wala_number cnt = 0;
        vector<chotka_wala_number> lengths_of_alternating_ab;

        for (chotka_wala_number i = 0; i < l - 1; i++)
        {
            if ((mera_string_variable[i] == 'a' && mera_string_variable[i + 1] == 'b') || (mera_string_variable[i] == 'b' && mera_string_variable[i + 1] == 'a'))
            {
                cnt++;
            }
            else
            {
                cnt++;
                if (cnt != 1)
                {
                    pb;
                }
                cnt = 0;
            }
            if (i == l - 2 && mera_string_variable[i] != mera_string_variable[i + 1])
            {
                cnt++;
                pb;
                cnt = 0;
            }
        }

        badka_wala_number final = 1;
        for (chotka_wala_number i = 0; i < lengths_of_alternating_ab.size(); i++)
        {
            badka_wala_number individual_calculation = 0;
            badka_wala_number temp = lengths_of_alternating_ab[i] / 2;
            for (chotka_wala_number j = 0; j <= temp; j++)
            {
                badka_wala_number num = (factorial_calc[lengths_of_alternating_ab[i]] * func(factorial_calc[lengths_of_alternating_ab[i] - j], p - 2, p)) % p;
                badka_wala_number den = factorial_calc[j];
                badka_wala_number result = (num * func(den, p - 2, p)) % p;
                individual_calculation += result;
                lengths_of_alternating_ab[i] -= 1;
            }
            final *= (individual_calculation % p);
            final %= p;
        }
        cout << final << "\n";
    }
    for (int i = 0; i < 100; i++)
        ;
    return 0;
}
