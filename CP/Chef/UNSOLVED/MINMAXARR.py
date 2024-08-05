import math as m

for virusarzk in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    s = sum(l)
    avg = s/n
    ss = 0
    for i in range(1,n+1):
        ss+=l[i-1]
        br = ss/i
        if(br>avg):
            print(m.ceil(br))
            break
    else:
        print(m.ceil(avg))