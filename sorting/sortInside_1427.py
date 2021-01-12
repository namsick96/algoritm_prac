f=open('../test.txt','r')

num=str(f.readline().strip())

charlist=[]
long=len(num)
for k in range(long):
    charlist.append(num[k])
charlist.sort(reverse=True)
s=""
for k in range(long):
    s+=charlist[k]
print(s)

