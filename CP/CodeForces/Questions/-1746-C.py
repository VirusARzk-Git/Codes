for t in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    # a=[]
    k=[]
    # d = {}
    r = [1]
    for i in range(1,len(l)):
        if(l[i-1]>l[i]):
            # a.append(i)
            k.append(l[i-1]-l[i])
            # d[k[len(k)-1]]=i
            r.insert(k[len(k)-1]-1,i+1)
    # print(a)
    # print(k)
    # print(d)
    for k in range(n-len(r)):
        print('1 ',end='')
    for k in range(len(r)):
        print(r[k],end=' ')
    print()