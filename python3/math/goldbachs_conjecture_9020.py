
f=open('./test.txt','r')
n=int(f.readline().strip())
for k in range(n):
    num=int(f.readline().strip())

    #에라스토네스의 체

    wholelist=[False,False]+([True]*(num-1))
    root=int(num**0.5)+1
    for p in range(2,root):
        if (wholelist[p]==True):
            for t in range(p+p,num+1,p):
                wholelist[t]=False

    #indexlist=[k for k in range(len(wholelist)) if wholelist[k]==True]
    #print(indexlist)
    a=num//2
    b=num-a

    while(True):
        if(wholelist[a]==True and wholelist[b]==True):
            print(a,b)
            break
        else:
            a-=1
            b+=1





