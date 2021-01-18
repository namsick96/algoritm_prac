import sys
class Stack():
    def __init__(self):
        self.items=[]
        self.count=0

    def pop(self):
        if self.count==0:
            return -1
        else:
            self.count-=1
            self.item=self.items[-1]
            del self.items[-1]
            return self.item

    def push(self,item):
        self.items.append(item)
        self.count+=1
        return

    def size(self):
        return self.count

    def reset(self):
        self.items=[]
        self.count=0



f=open('../test.txt','r')

target1=['(','[']

line=""
while (True):
    line=f.readline().strip('\n')
    if line==".":
        break
    stack=Stack()
    trouble=False
    for i in line:
        if i =='(' or i=='[':
            stack.push(i)
        elif i==')':
            item=stack.pop()
            if item=='(':
                continue
            else:
                trouble=True
                break

        elif i==']':
            item=stack.pop()
            if item=='[':
                continue
            else:
                trouble=True
                break
    if (not trouble) and stack.size()==0:
        print("yes")
    else:
        print("no")


