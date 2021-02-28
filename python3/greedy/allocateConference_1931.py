import sys
f=open('../test.txt', 'r')

num=int(f.readline().strip())

ready=[]
ans=[]
for k in range(num):
    time=tuple((map(int,f.readline().strip().split())))
    ready.append(time)

ready.sort(key = lambda x: (x[1], x[0]))



for q in ready:
    if len(ans)==0:
        ans.append(q)
    else:
        if ans[-1][1]<=q[0]:
            ans.append(q)

print(len(ans))

