// #include <conio.h>
// #include <stdio.h>
// #include <string>
#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main()
{
int kal;
cin>>kal;
while(kal--)
{
    int nn , x;
    int c=0,d=0;
    cin >> nn >> x;
    int a[nn];
    for(int i=0;i<nn;i++)
    cin>>a[i];
    for(int i=0;i<nn;i++)
    {
        if(a[i]==x)
        {   c=1;    d=1; break; }
        else if(a[i]>x)
        c=1;
        else
        d=1;
        if(c==1 && d==1)
        break;   
    }
    if(c==1 && d==1)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}
return 0;
}