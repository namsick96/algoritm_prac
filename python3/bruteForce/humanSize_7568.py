import sys

f=open('../test.txt', 'r')

num=int(f.readline().strip())
wholelist=[]
for k in range(num):
    element=list(map(int,f.readline().strip().split()))
    wholelist.append(element)

ranklist=[]
for k in range(num):
    count=1
    weight=wholelist[k][0]
    height=wholelist[k][1]
    for j in range(num):
        otherweight=wholelist[j][0]
        otherheight=wholelist[j][1]
        if (otherheight>height and otherweight>weight):
            count+=1
    ranklist.append(count)
for k in ranklist:
    print(k,end=' ')