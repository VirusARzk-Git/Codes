# cook your d==h here
for i in range(int(input())):
    a, b = map(int, input().split())
    if a==b :
        print("YES")
    else:
        m1 = min(a, b)
        m2 = max(a, b)
        for i in range(6):
            m1 *= 2
            if (m1 == m2):
                print("YES")
                break
        else:
            print("NO")
