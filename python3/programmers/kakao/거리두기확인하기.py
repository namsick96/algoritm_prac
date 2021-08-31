import math


def solution(places):
    xmove1 = [0, 0, -1, 1]
    ymove1 = [1, -1, 0, 0]

    xmove2 = [-1, -1, 1, 1]
    ymove2 = [1, -1, 1, -1]

    xmove3 = [2, -2, 0, 0]
    ymove3 = [0, 0, 2, -2]

    answer = []
    for board in places:
        wrong = False
        for y in range(0, 5):
            for x in range(0, 5):
                if (board[y][x] == "P"):
                    # move1
                    for i in range(0, 4):
                        tempy = y + ymove1[i]
                        tempx = x + xmove1[i]
                        if (tempy < 0 or tempy > 4 or tempx < 0 or tempx > 4):
                            continue
                        else:
                            if (board[tempy][tempx] == "P"):
                                wrong = True
                                break
                    # move2
                    for i in range(0, 4):
                        tempy = y + ymove2[i]
                        tempx = x + xmove2[i]
                        if (tempy < 0 or tempy > 4 or tempx < 0 or tempx > 4):
                            continue
                        else:
                            if (board[tempy][tempx] == "P"):
                                if (board[tempy][x] == "X" and board[y][tempx] == "X"):
                                    continue
                                else:
                                    wrong = True
                                    break
                    # move3
                    for i in range(0, 4):
                        tempy = y + ymove3[i]
                        tempx = x + xmove3[i]
                        if (tempy < 0 or tempy > 4 or tempx < 0 or tempx > 4):
                            continue
                        else:
                            if (board[tempy][tempx] == "P"):
                                tempy2 = int((tempy + y) / 2)
                                tempx2 = int((tempx + x) / 2)
                                if (board[tempy2][tempx2] != "X"):
                                    wrong = True
                                    break
                                else:
                                    continue

                else:
                    continue
                if (wrong):
                    break
            if (wrong):
                break
        if (wrong):
            answer.append(0)
        else:
            answer.append(1)

    return answer