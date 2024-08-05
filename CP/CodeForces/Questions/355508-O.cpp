#include <bits/stdc++.h>
using namespace std;

int main()
{
    double price, price2;
    int hh, mm, h, d, c, n;
    cin >> hh >> mm >> h >> d >> c >> n;
    if (h % n == 0)
        price = double(h / n) * c;
    else
        price = double(h / n + 1) * c;
    double mins = hh * 60 + mm;
    if (mins < 20 * 60)
    {
        mins = 20 * 60 - mins;
        int hu = h + mins * d;
        if (hu % n == 0)
            price2 = double(hu / n) * c;
        else
            price2 = double(hu / n + 1) * c;
        price2 = price2 * 0.8;
        if (price2 < price)
            price = price2;
    }
    else
    {
        price = 0.8 * price;
        // return 0;
    }
    printf("%.3f", price);

    return 0;
}