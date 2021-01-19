import sys

f=open('../test.txt','r')
num=int(f.readline().strip())
sequence=list(map(int,f.readline().split()))
stack=[]
ans=[-1 for k in range(num)]
for k in range(num):
    while stack and sequence[stack[-1]]<sequence[k]:
        ans[stack[-1]]=sequence[k]
        del stack[-1]
    stack.append(k)
print(" ".join(map(str,ans)))