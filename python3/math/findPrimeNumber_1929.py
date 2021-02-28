import math

f=open('./test.txt','r')
a,b=map(int,f.readline().rstrip().split())

wholelist=[False,False]+[True]*(b-1)

#어떤 값의 약수중 제일 작은 값은 sqrt(N) 보다 같거나 작다.
n=int(b**0.5)+1
for i in range(2,n):
    if (wholelist[i]==True):
        for j in range(2*i,b+1,i):
            wholelist[j]=False



#primelist=[k for k in range(1,b+1) if wholelist[k]==True]

for k in range(a,b+1):
    if wholelist[k]==True:
        print(k)