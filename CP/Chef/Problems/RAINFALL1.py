for i in range(int(input())):
    a = int(input())
    if a < 3:
        print('LIGHT')
    elif a<7:
        print('MODERATE')
    else:
        print('HEAVY')