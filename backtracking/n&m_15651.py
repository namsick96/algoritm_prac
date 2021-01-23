def perm(lst,n):
    ans=[]
    if n==1:
        for k in lst:
            ans.append([k])
    else:
        for temp in perm(lst[:],n-1):
            for i in lst:
                ans.append(temp+[i])
    return ans




f=open('../test.txt','r')
a,b=map(int,f.readline().strip().split())
numbers=[k for k in range(1,a+1)]

result=perm(numbers,b)
for k in result:
    print(" ".join(map(str,k)))