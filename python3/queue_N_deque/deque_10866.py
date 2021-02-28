from collections import deque


f=open('../test.txt', 'r')
num=int(f.readline().strip())
deque1=deque()
for k in range(num):
    line=f.readline().strip().split()
    if line[0]=='push_back':
        deque1.append(line[1])
    elif line[0]=='push_front':
        deque1.appendleft(line[1])
    elif line[0]=='pop_front':
        if len(deque1)==0:
            print(-1)
        else:
            print(deque1.popleft())
    elif line[0]=='pop_back':
        if len(deque1)==0:
            print(-1)
        else:
            print(deque1.pop())
    elif line[0]=='size':
        print(len(deque1))
    elif line[0]=='empty':
        if len(deque1)==0:
            print(1)
        else:
            print(0)
    elif line[0]=='front':
        if len(deque1)==0:
            print(-1)
        else:
            print(deque1[0])
    elif line[0]=='back':
        if len(deque1)==0:
            print(-1)
        else:
            print(deque1[-1])
    else:
        continue







