for test_case in range(int(input())):
    n,k = map(int,input().split())
    l = list(map(int,input().split()))
    if n!=1:
        l.pop()
    if k in l:
        print('Yes')
    else:
        print('No')