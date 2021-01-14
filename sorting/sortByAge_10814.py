f=open('../test.txt','r')

innum=int(f.readline().strip())
wholelist=[]

for k in range(innum):
    a,b=f.readline().strip().split()
    a=int(a)
    pack=[a,k,b]
    wholelist.append(pack)

wholelist.sort()

for k in wholelist:
    print(k[0],k[2])
