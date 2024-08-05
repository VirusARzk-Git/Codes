for i in range(int(input())):
    a,b = map(int,input().split())
    m = max(a,b)
    c=m
    n=(m-1)**2
    m=m**2
    if a==c:
        if c%2==1:
            b+=n
        else:
            b=m-b+1
        print(b)
    else:
        if c%2==1:
            a=m-a+1
        else:
            a=n+a
        print(a)
