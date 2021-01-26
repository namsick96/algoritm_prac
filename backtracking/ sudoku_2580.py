import sys
f=open('../test.txt','r')
board=[]
for k in range(9):
    line=list(map(int,f.readline().strip().split()))
    board.append(line)

zeros=[(i,j)for i in range(9) for j in range(9) if board[i][j]==0]

def promissing(x,y):
    materials=[1,2,3,4,5,6,7,8,9]
    if board[x][y]==0:
        #가로 체크
        tempx=[]
        tempx=board[x]
        xnotin=list(set(materials)-set(tempx))
        if len(xnotin)==1:
            board[x][y]=xnotin[0]
            return True
        else:
            pass
        #세로 체크
        tempy=[]
        for k in range(9):
            tempy.append(board[k][y])
        ynotin=list(set(materials)-set(tempy))
        if len(ynotin)==1:
            board[x][y]=ynotin[0]
            return True
        else:
            pass
        # 사각형 체크
        tempx=x//3
        tempy=y//3
        temps=[]
        for p in range(tempx*3,(tempx+1)*3):
            for q in range(tempy*3,(tempy+1)*3):
                temps.append(board[p][q])
        snotin=list(set(materials)-set(temps))
        if len(snotin)==1:
            board[x][y]=snotin[0]
            return True
        #다안될 경우 queue끝에 넣어 놓기.
        else:
            return False
flag=False
def dfs(x):
    global flag

    if flag:
        return

    if x==len(zeros):
        for k in board:
            print(" ".join(map(str, k)))
        flag=True
        return
    else:
        (i,j)=zeros[x]
        tf=promissing(i,j)
        if tf:
            dfs(x+1)
            board[i][j]=0

dfs(0)

#시간초과 계속 난다...


