for i in range(int(input())):
    n,a,b  = map(int,input().split())
    c=0
    while n>1:
        c+=1
        n/=2
    print(c*a+c*b-b)
    # m = max(a)
    # if(m > sum(a)-m):
    #     print('Yes')
    # else:
    #     print('No')