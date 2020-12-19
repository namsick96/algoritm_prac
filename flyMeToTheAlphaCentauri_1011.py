
f=open('./test.txt','r')
n=int(f.readline().rstrip())
for k in range(n):
    start,end=map(int,f.readline().rstrip().split())

    go=end-start
    turn=1
    level=1
    range=1
    temp=1
    while(go>=range+level):
        if (temp==1):
            range=range+level
            turn+=1
            temp+=1

            continue
        if (temp==2):
            range=range+level

            level+=1
            turn+=1
            temp=1
            continue

    print(turn)







f.close()