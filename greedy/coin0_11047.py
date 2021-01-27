

f=open('../test.txt','r')

nin,kin=map(int,f.readline().strip().split())

coins=[]
for k in range(nin):
    get=int(f.readline().strip())
    coins.append(get)

idx=len(coins)-1
count=0
while(kin!=0):
    singlecoin=coins[idx]
    if singlecoin<=kin:
        kin=kin-singlecoin
        count+=1
    else:
        idx-=1
print(count)
