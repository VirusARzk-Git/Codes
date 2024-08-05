for i in range(int(input())):
    a = input()
    l = list(map(int,input().split()))
    c=0
    for a in l:
        if a%2==1:
            c+=1
    if c > 0 and c %2==0:
        print('Yes')
    else:
        print('No')