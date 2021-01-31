def solution(board):
    collen = len(board[0])
    rowlen = len(board)
    biggest = 0
    if collen == 1 or rowlen == 1:
        for i in range(rowlen):
            for j in range(collen):
                if board[i][j]==1:
                    return 1
        return 0

    for i in range(1,rowlen):
        temp=[]
        for j in range(1,collen):
            if board[i][j] == 1:
                board[i][j]=min(board[i-1][j-1],board[i-1][j],board[i][j-1])+1
                biggest=max(biggest,board[i][j])


    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    return biggest**2

solution([[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]])
#solution([[0,0,1,1],[1,1,1,1]])