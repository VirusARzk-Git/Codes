from math import gcd


for i in range(int(input())):
    a,b = map(int, input().split())
    if(gcd(a,b)==1):
        print(a*b-a-b+1)
    else:
        print(-1)