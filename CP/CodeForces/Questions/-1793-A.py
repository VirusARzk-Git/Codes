import math
for virus in range(int(input())):
    a,b = map(int,input().split())
    n,m = map(int,input().split())
    c = (a*m)/(m+1)
    sum=0
    if(m>=n):
        print(min(a,b)*n)
        continue
    if(c<b):
        sum = math.ceil((n-n%(m+1))*c)
    else:
        print(b*n)
        continue
    n = n%(m+1)
    if(n!=0):
        if(a<b):
            sum+=(a*n)
        else:
            sum+=(b*n)
    print(sum)
