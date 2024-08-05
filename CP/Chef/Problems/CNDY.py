for i in range(int(input())):
    a = input()
    l = list(map(int,input().split()))
    for i in l:
        if(l.count(i)>2):
            print('No')
            break
    else:
        print('Yes')