l=[0]
n = int(input())
for i in range(n):
    l.append((l[-1]+(i+1)))
for i in range(n):
    if i<1:
        print(0)
    elif i<2:
        print(6)
    else:
        print(((i+1)*(i+1)*((i+1)*(i+1)-1))//2-8*l[i-1])