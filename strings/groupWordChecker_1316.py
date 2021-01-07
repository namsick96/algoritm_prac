import sys

with open("test.txt", "r") as f:
    n = int(f.readline().rstrip())
    list1 = []
    for k in range(n):
        list1.append(f.readline().rstrip())
        # 리스트에 입력값 받음.
    count=0
    for k in range(n):
        target=list1[k]
        length=len(target)
        checked_char=[]
        groupString=True
        for p in range(length):
            if (target[p] in checked_char):
                if (target[p-1]==target[p]):
                    continue
                else:
                    groupString=False
                    break

            else:
                checked_char.append(target[p])
        if (groupString):
            count=count+1
    print(count)

