import math
import sys
from itertools import combinations,permutations

def backtrack(table,n):

    #teamarr=teamMaker(n)
    teamarr=list(combinations([k for k in range(1,n+1)],n//2))
    print(teamarr)
    half=int(n/2)
    gap=100000000000000
    for i in range(len(teamarr)//2):

        ascore=0
        bscore=0
        targetteam=teamarr[i]
        for p in targetteam:
            for q in targetteam:
                ascore+=table[p-1][q-1]

        targetteam=teamarr[-1-i]
        for p in targetteam:
            for q in targetteam:
                bscore+=table[p-1][q-1]
        #print(ascore)
        #print(bscore)
        gap=min(gap,abs(ascore-bscore))
        #print(gap)
    return gap

#팀을 나누고 두 선수가 짝지어지는 경우를 다 구하자
#이건 순열임. 조합이 아님!!!
#근데 조합으로 하고 위에서 바꿔서 더하는걸로 해보자. 메모리 아껴보
def pair(lst):
    stack = []
    result = []
    idxlist = [k for k in range(0, len(lst))]
    for i in idxlist[:len(idxlist)-1]:
        stack.append([i])

    while stack:
        cur = stack.pop()
        if len(cur) == 2:
            case=[]
            for k in cur:
                case.append(lst[k])
            result.append(case)
        else:
            for k in range(cur[-1]+1,len(idxlist)):
                stack.append(cur + [k])
    return result


#팀을 나눠보자.
def teamMaker(n):
    #dfs으로 n!의 경우수 나열하기
    lst=[k for k in range(1,n+1)]
    stack=[]
    result=[]
    for i in range(1,n+1):
        stack.append([i])

    while stack:
        cur=stack.pop()
        if len(cur)==n:
            result.append(cur)
        else:
            for k in lst:
                if k not in cur:
                    stack.append(cur+[k])
                else:
                    pass
    return result



f=open('../test.txt', 'r')

num=int(f.readline().strip())
table=[]
for k in range(num):
    line=list(map(int,f.readline().strip().split()))
    table.append(line)

#print(pair([1,2,3,4]))
print(backtrack(table,num))