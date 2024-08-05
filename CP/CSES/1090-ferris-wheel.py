n , x = map(int,input().split())
l = list(map(int,input().split()))
l.sort()
i=0;j=n-1;c=0
while(1):
    if i==j+1:
        break
    if l[i]+l[j]<=x:
        i+=1
        j-=1
        c+=1
    elif l[i]+l[j]>x:
        c+=1
        j-=1
    if i==j:
        c+=1
        j-=1
print(c)