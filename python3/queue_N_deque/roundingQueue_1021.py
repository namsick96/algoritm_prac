import sys
from collections import deque

f=open('../test.txt', 'r')
a,b=map(int,f.readline().split())
items=[k for k in range(1,a+1)]
line=list(map(int,f.readline().split()))
deque1=deque(items)
count=0
for i in range(len(line)):
    length=len(deque1)
    #이줄에서 if items[0]이라고 해서 한참 헤멤
    if deque1[0]==line[i]:
        deque1.popleft()
        continue

    idx = deque1.index(line[i])
    if idx<=length//2:
        #rm
        deque1.rotate(-1*idx)
        deque1.popleft()
        count=count+idx
        continue
    else:
        #lm
        deque1.rotate((length-idx))
        deque1.popleft()
        count=count+length-idx
        continue

print(count)