c = 1

def doThis():

    global c

    for i in (1, 2, 3): 
        c += 1

for i in (1, 2, 3):
    doThis()

print (c)
