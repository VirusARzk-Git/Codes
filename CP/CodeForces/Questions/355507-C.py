n = int(input())
a = list(map(int,input().split()))
s = set()
c = 0
for i in a:
    if i in s:
        print(c,end=' ')
    else:
        s.add(i)
        c+=1
        print(c,end=' ')