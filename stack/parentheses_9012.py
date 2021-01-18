import sys

class Stack():
    def __init__(self):
        self.items=[]
        self.count=0
    def push(self,item):
        self.items.append(item)
        self.count+=1
        return

    def pop(self):
        if self.count==0:
            return -1
        else:
            item=self.items[-1]
            del self.items[-1]
            self.count-=1
            return item

    def size(self):
        return self.count

f=open('../test.txt','r')

num=int(f.readline().strip())

for k in range(num):
    idx=0
    stack=Stack()
    line=f.readline().strip()
    for i in range(len(line)):
        if line[i]=='(':
            stack.push('(')
        else:
            popped=stack.pop()
            if popped==-1:
                idx=-1
                print('NO')
                break
    if idx==-1:
        continue
    if stack.size()!=0:
        print("NO")
    else:
        print("YES")
