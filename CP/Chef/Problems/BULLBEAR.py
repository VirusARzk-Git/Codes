for i in range(int(input())):
    a,b = map(int, input().split())
    if a<b:
        print('PROFIT')
    elif a>b:
        print('LOSS')
    else:
        print('NEUTRAL')