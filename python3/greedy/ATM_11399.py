

f=open('../test.txt', 'r')

num=int(f.readline().strip())
persons=[k for k in range(1,num+1)]
times=list(map(int,f.readline().strip().split()))

aa=list(zip(persons,times))
aa.sort(key=lambda x:x[1])
sumup=0
ans=0
for k in aa:
    sumup+=k[1]
    ans=ans+sumup
print(ans)