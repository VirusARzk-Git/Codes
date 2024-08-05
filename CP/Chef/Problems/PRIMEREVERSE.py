for i in range(int(input())):
    n = int(input())
    a = input()
    k = 2
    l = -1*n
    for j in range(len(a)):
        if a[j]=='1':
            if l%2==0 and l > -1:
                k=1
            l = 0
        else:
            l += 1
    print(k)