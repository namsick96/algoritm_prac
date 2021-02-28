import sys

def dfs_comb2(lst, n):
    #dfs인 경우 n==1이면 이렇게 해줘야함.
    if n==1:
        return [[k] for k in lst]
    ret = []
    idx = [i for i in range(len(lst))]

    stack = []
    for i in idx[:len(lst) - n + 1]:
        stack.append([i])

    while len(stack) != 0:
        cur = stack.pop()

        for i in range(cur[-1] + 1, len(lst) - n + 1 + len(cur)):
            temp = cur + [i]
            if len(temp) == n:
                element = []
                for i in temp:
                    element.append(lst[i])
                ret.append(element)
            else:
                stack.append(temp)
    return ret

f=open('../test.txt', 'r')
a,b=map(int,f.readline().strip().split())



ans=dfs_comb2([k for k in range(1,a+1)],b)
ans.sort()
for i in ans:
    s=" ".join(map(str,i))
    print(s)

