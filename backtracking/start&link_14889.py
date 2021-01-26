import math
import sys
from itertools import combinations,permutations

def backtrack(table,n):

    #teamarr=teamMaker(n)
    teamarr=permutations([k for k in range(1,n+1)],n)
    half=int(n/2)
    gap=100000000000000
    for i in teamarr:
        teama = list(combinations(i[:half],2))
        teamb = list(combinations(i[half:],2))

        #print(teamb)

        ascore=0
        bscore=0
        for j in range(0,len(teama)):
            a,b=teama[j][0],teama[j][1]
            ascore+=table[a-1][b-1] +table[b-1][a-1]
            c,d=teamb[j][0],teamb[j][1]
            bscore+=table[c-1][d-1]+table[d-1][c-1]
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



f=open('../test.txt','r')

num=int(f.readline().strip())
table=[]
for k in range(num):
    line=list(map(int,f.readline().strip().split()))
    table.append(line)

#print(pair([1,2,3,4]))
print(backtrack(table,num))