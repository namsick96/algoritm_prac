

f=open('./test.txt','r')

while (True):
    num=int(f.readline().rstrip())
    if (num==0):
        break
    if (num==1):
        print(1)
        continue
    end=2*num
    wholelist=[False,False]+[True]*(end-1)

    n=int(end**0.5)+1
    for k in range(2,n):
        if wholelist[k]==True:
            for j in range(k+k,end+1,k):
                wholelist[j]=False
    real=wholelist[num+1:]
    print(sum(real))


