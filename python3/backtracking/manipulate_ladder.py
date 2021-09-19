from itertools import combinations
import copy
def check1():
    for i in range(1,N+1):
        idx=i
        for y in range(1,H+1):
            if(board[y][idx]==True):
                idx=idx+1
            elif(board[y][idx-1]==True):
                idx=idx-1
        if(idx!=i):
            return False
    return True


def dfs(cnt,x,y):
    global ans
    if(check1()):
        ans=min(ans,cnt)
        return
    elif cnt==3 or ans<=cnt:
        return
    for i in range(x,H+1):
        if i==x:
            k=y
        else:
            k=0
        for j in range(k,N):
            if board[i][j]==False and board[i][j+1]== False:
                if j>0 and board[i][j-1]==True:
                    continue
                board[i][j]=1
                dfs(cnt+1,i,j+2)
                board[i][j]=0




f=open('./test.txt', 'r')

N,M,H=map(int,f.readline().strip().split())
lines=[]
for k in range(M):
    line=map(int,f.readline().split())
    lines.append(line)
board=[[False for k in range(N+1)] for k in range(H+1)]
for line in lines:
    board[line[0]][line[1]]=True
if (M==0):
    print(0)
    exit(0)

ans=4
dfs(0,0,0)
print(ans if ans<4 else -1)

