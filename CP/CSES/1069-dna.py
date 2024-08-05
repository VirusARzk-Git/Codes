a = input()
c=1;max=1
for i in range(1,len(a)):
    if a[i-1] == a[i]:
        c+=1
        if max<c:
            max=c
    else:
        c=1
print(max)