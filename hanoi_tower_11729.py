import sys
def hanoi(n,start,end,middle):
    global move
    if n==1:
        move.append([start,end])
        return
    else:
        hanoi(n-1,start, middle,end)
        move.append([start,end])
        hanoi(n-1,middle,end,start)

move=[]
hanoi(num,1,3,2)
print(len(move))
for k in move:
    print(k[0],k[1])

