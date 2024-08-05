for i in range(int(input())):
    n,m,k,x  = map(int,input().split())
    j = k*n+m
    x = x%j
    x = x-(k-1)*n
    if x>0:
        print('Yes')
    else:
        print('No')
    # print(c*a+c*b-b)
    # m = max(a)
    # if(m > sum(a)-m):
    #     print('Yes')
    # else:
    #     print('No')