def TOH(n,a=1,b=2,c=3):
    if n>0:
        TOH(n-1,a,c,b)
        print(a,c)
        TOH(n-1,b,a,c)

n = int(input())
pr =1
for i in range(1,n):
    pr = pr*2+1
print(pr)

TOH(n)