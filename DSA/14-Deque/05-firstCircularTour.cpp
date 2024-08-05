#include <iostream>
using namespace std;

int firstCircularTour(int *petrol, int *dist, int n)
{
    int start = 0, currPetrol = 0, prevPetrol = 0;
    for (int i = 0; i < n; i++)
    {
        currPetrol += (petrol[i] - dist[i]);
        if (currPetrol < 0)
        {
            start = i + 1;
            prevPetrol += currPetrol;
            currPetrol = 0;
        }
    }
    return ((currPetrol + prevPetrol) >= 0) ? (start + 1) : -1;
}

int main()
{
    int n;
    cin >> n;
    int petrol[n], dist[n];
    for (int i = 0; i < n; i++)
        cin >> petrol[i];
    for (int i = 0; i < n; i++)
        cin >> dist[i];
    cout << firstCircularTour(petrol, dist, n);
    return 0;
}