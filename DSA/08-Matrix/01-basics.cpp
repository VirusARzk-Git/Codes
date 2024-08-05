#include <iostream>
using namespace std;

// Elements are stored in Row-Major Order
// Internal Curly Brackets are optional
// Only the first dimension can be omitted when we intitalize

int main()
{
    int arr[3][2] = {{10, 20},
                     {30, 40},
                     {50, 60}};
    // int arr[3][2] = {10, 20, 30, 40, 50, 60};
    // int arr[][2] = {10, 20, 30, 40, 50, 60};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            cout << arr[i][j] << ' ';
    return 0;
}