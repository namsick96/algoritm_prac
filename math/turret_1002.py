f=open('./test.txt','r')

n=int(f.readline().strip())

for k in range(n):
    x1,y1,r1,x2,y2,r2=map(int,f.readline().strip().split())
    distance = (((x1 - x2) ** 2 + (y1 - y2) ** 2) ** (0.5))

    roundsum = r1 + r2
    if (r2>=r1):
        roundminus=r2-r1
    else:
        roundminus=r1-r2

    if (distance==0):
        if (r1==r2):
            print(-1)
            continue
        else:
            print(0)
            continue
    else:
        if (distance==roundsum):
            print(1)
            continue
        elif(roundminus<distance and distance<roundsum):
            print(2)
            continue
        elif(distance==roundminus):
            print(1)
            continue
        else:
            print(0)


