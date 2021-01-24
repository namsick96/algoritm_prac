def backtrack(n):
    ret=0
    stack=[]
    idx=[k for k in range(1,n+1)]
    for i in idx:
        stack.append([i])

    while(stack):
        cur=stack.pop()
        if len(cur)==n:
            ret+=1
        notlist=[]
        for t in range(len(cur)):
            lineidx=cur[t]
            gap=len(cur)-t
            notlist.append(lineidx)
            notlist.append(lineidx+gap)
            notlist.append(lineidx-gap)

        for p in idx:
            if p not in notlist:
                temp=cur+[p]
                stack.append(temp)
            else:
                pass
    return ret

# def backtrack2(n):
#     ret=0
#     idx = [k for k in range(1, n + 1)]
#
#     for i in idx:



f=open('../test.txt','r')
a=int(f.readline().strip())
print(backtrack(a))

