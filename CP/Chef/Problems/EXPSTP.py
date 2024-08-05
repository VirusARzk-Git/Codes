for i in range(int(input())):
    n,x1,y1,x2,y2 = map(int,input().split())
    a = abs(x1 - x2)+abs(y1 - y2)
    b = min(n - max(x1,y1)+1,min(x1,y1)) + min(min(x2,y2), n - max(x2,y2)+1)
    # print(max(a,b))
    print(min(a,b))
    # print(a,b)