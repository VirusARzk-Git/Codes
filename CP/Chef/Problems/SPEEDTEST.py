# https://www.codechef.com/SEP221C/problems/BOBBANK

for _ in range(int(input())):
    a, b, x, y = map(int, input().split())
    if(a/x > b/y):
        print("Alice")
    elif(a/x < b/y):
        print('Bob')
    else:
        print('Equal')
