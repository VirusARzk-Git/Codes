// debug the following code

#include <iostream>
using namespace std;

int main()
{
    int bikes, cars;
    cin >> bikes >> cars;
    int total_tires = bikes * 2 + cars * 2;
    cout << "Total tires: " << total_tires;
    return 0;
}