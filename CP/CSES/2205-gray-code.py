# n = int(input())
# l = []
# for i in range(n*n):
#     l.append('0'*n)
# print()

num = int(input())
print('0'*num)
print('0'*(num-1)+'1')
for k in range(2,2**num):
    b = []
    n=k
    while(n>0):
        b.append(n%2)
        n//=2
    s=''
    for j in range(len(b)-2,-1,-1):
        if(b[j]==b[j+1]):
            s+='0'
        else:
            s+='1'
    s=str(b[-1])+s

    if len(b)<num:
        for i in range(num-len(b)):
            s='0'+s
    print(s)
