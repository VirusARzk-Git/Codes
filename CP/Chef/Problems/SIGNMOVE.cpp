#include <iostream>
// #include <conio.h>
// #include <stdio.h>
// #include <string>
// #include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
// system("cls");
int t;  cin>>t;
while(t--)
{
    ll s=0,n,i=1;
    cin>>n;
    if(n%2==0)
    s=n/2;
    else
    s=(-1)*(n/2+1);
    cout<<s<<endl;
}
return 0;
}