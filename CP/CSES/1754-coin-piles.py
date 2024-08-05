for i in range(int(input())):
    a,b = map(int,input().split())
    c=max(a,b)
    b=min(a,b)
    a=c
    if (a%3+b%3)%3==0 and a<=b*2:
        print('YES')
    else:
        print('NO')
