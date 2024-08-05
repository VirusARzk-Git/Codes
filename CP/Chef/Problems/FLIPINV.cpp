#include <iostream>
// #include <conio.h>
// #include <stdio.h>
// #include <string>
// #include <bits/stdc++.h>
// #define ll unsigned long long int
using namespace std;

int main()
{
// system("cls");
int t;
cin>>t;
while (t--)
{
    int n , k;
    cin>>n>>k;
    string s;
    cin>>s;
    int i,j,  c = 0 , su=0 , n0=0, n1=0;
    for( i=n-1; i>=0; i--)
    {
        if(s[i]=='0')
        n0++;
        else
        n1++;
    }
if(n0<n1)
{
    for( i=n-1; i>=0;i--)
    {
        if(s[i]=='0' && k>0)
        k--;
        if(k==0)
        break;
    }
    for (j = 0; j < i; j++)
    {
        if(s[j]=='1')
        c++;
        else
        su+=c;
    }
}
else
{
    for( i=0; i<n; i++)
    {
        if(s[i]=='1' && k>0)
        {   s[i]='0';    k--;       }
        if(k==0)
        break;
    }
    for (j = 0; j < n; j++)
    {
        if(s[j]=='1')
        c++;
        else
        su+=c;
    }
}
    cout<<su<<endl;
}

return 0;
}