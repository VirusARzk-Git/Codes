for i in range(int(input())):
    a  = list(map(int,input().split()))
    m = max(a)
    if(m > sum(a)-m):
        print('Yes')
    else:
        print('No')