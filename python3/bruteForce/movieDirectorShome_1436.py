import re

num=3
start=666
count=0
target=re.compile('6{3}')

while (True):
    if count==num:
        print(start-1)
        break
    temp=str(start)
    m=target.search(temp)
    if m!=None:
        count+=1
    start+=1
