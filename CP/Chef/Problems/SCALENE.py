for i in range(int(input())):
    a,b,c = map(int,input().split())
    if a==b or b==c or c==a:
        print('NO')
    elif c>=(a+b):
        print('NO')
    else:
        print('YES')