n = int(input())
if n % 4 <= 2 and n%4!=0 :
    print('NO')
else:
    print('YES')
    if n%2==0:
        print(n//2)
        for i in range(n//4):
            print(i+1,end=' ')
        for i in range(n-n//4,n):
            print(i+1,end=' ')
        print()
        print(n//2)
        for i in range(n//4,n-n//4):
            print(i+1,end=' ')
    else:
        n+=1
        print(n//2)
        for i in range(n//4):
            print(i+1,end=' ')
        print(n//2,end=' ')
        for i in range(n-n//4,n-1):
            print(i+1,end=' ')
        print()
        print(n//2-1)
        for i in range(n//4,n-n//4):
            if((i+1)!=n//2):
                print(i+1,end=' ')