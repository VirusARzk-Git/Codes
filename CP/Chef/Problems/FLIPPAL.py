for _ in range(int(input())):
    n = int(input())
    s = input()
    if n%2==1:
        print('YES')
        continue
    a = b = 0
    for i in range(n):
        if s[i]=='0':
            a+=1
        else:
            b+=1
    if a%2==0 and b%2==0:
        print('YES')
    else:
        print('NO')

    
