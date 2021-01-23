import sys

def perm(lst,n):
    stack=[]
    ans=[]

    if n==1:
        for k in lst:
            ans.append([k])
        return ans

    idx=[k for k in range(len(lst))]
    for i in idx:
        stack.append([i])

    while len(stack)!=0:
        cur=stack.pop()
        last=cur[-1]
        if len(cur)==n:
            ele=[]
            for k in cur:
                ele.append(lst[k])
            ans.append(ele)
        else:
            for j in range(last,len(lst)):
                stack.append(cur+[j])
    return ans






f=open('../test.txt','r')
a,b=map(int,f.readline().strip().split())
numbers=[k for k in range(1,a+1)]

result=perm(numbers,b)
result.sort()

for k in result:
    print(" ".join(map(str,k)))